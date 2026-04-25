/*
Functional
System should send notifications via:
Email
SMS
Push notification
A user can have multiple notification preferences
Event example:
“Order Placed” → notify via Email + SMS
Easy to add new channels later (e.g., WhatsApp)

Non-functional (light)
Extensible
Maintainable
No need to design distributed system / queues

-----------------------------------------------

Answer in this structure:

1. Entities / Models

(What are the core objects?)

2. Interfaces (very important)

(Where will you apply abstraction?)

3. Class Design

(High-level classes + responsibilities)

4. Flow

(What happens when an event occurs?)

5. Extensibility

(How would you add WhatsApp later?)

*/

type User = {
  id: string;
  email: string;
  phone: string;
  deviceToken?: string;
};

enum NotificationChannelType {
  EMAIL = "email",
  SMS = "sms",
  PUSH = "push",
}

// SRP: This model only represents user preferences (no logic here)
type NotificationPreference = {
  userId: string;
  channels: NotificationChannelType[];
};

// DIP: High-level modules depend on abstraction, not DB implementation
interface NotificationPreferenceRepository {
  getUserPreferences(userId: string): Promise<NotificationChannelType[]>;
}

// SRP: This class ONLY handles data access
// Can be replaced by DB/Redis implementation without affecting service (OCP + DIP)
class InMemoryPreferenceRepository implements NotificationPreferenceRepository {
  private store = new Map<string, NotificationChannelType[]>();

  async getUserPreferences(userId: string): Promise<NotificationChannelType[]> {
    return this.store.get(userId) || [];
  }

  seed(userId: string, channels: NotificationChannelType[]) {
    this.store.set(userId, channels);
  }
}

// STRATEGY PATTERN + DIP:
// Defines interchangeable behavior for different notification channels
interface NotificationChannel<TPayload> {
  send(payload: TPayload): Promise<void>;
}

// ISP: Each channel gets only what it needs

type EmailPayload = {
  to: string[];
  subject: string;
  body: string;
};

type SmsPayload = {
  to: string[];
  message: string;
};

type PushPayload = {
  to: string[];
  title: string;
  body: string;
};

// SRP: Only responsible for sending Email
// LSP: Can be used anywhere NotificationChannel<EmailPayload> is expected
class EmailChannel implements NotificationChannel<EmailPayload> {
  async send(payload: EmailPayload) {
    console.log("EMAIL:", payload);
  }
}

// Same pattern repeated → polymorphism (LSP)
class SmsChannel implements NotificationChannel<SmsPayload> {
  async send(payload: SmsPayload) {
    console.log("SMS:", payload);
  }
}

class PushChannel implements NotificationChannel<PushPayload> {
  async send(payload: PushPayload) {
    console.log("PUSH:", payload);
  }
}

// FACTORY PATTERN:
// Centralizes object creation logic
// OCP: Add new channel without modifying consumer code
class NotificationChannelFactory {
  private static channels = {
    [NotificationChannelType.EMAIL]: new EmailChannel(),
    [NotificationChannelType.SMS]: new SmsChannel(),
    [NotificationChannelType.PUSH]: new PushChannel(),
  };

  static getChannel<T extends NotificationChannelType>(
    type: T,
  ): NotificationChannel<any> {
    return this.channels[type];
  }
}

// Ensures compile-time correctness of payload per channel
// Prevents runtime mismatch → strong type safety
type ChannelPayloadMap = {
  [NotificationChannelType.EMAIL]: EmailPayload;
  [NotificationChannelType.SMS]: SmsPayload;
  [NotificationChannelType.PUSH]: PushPayload;
};

// SRP: Responsible ONLY for transforming domain data → channel payload
// OCP: Adding new channel → extend switch, no service change
class NotificationPayloadBuilder {
  static build<K extends NotificationChannelType>(
    type: K,
    users: User[],
    data: { title: string; message: string },
  ): ChannelPayloadMap[K] {
    switch (type) {
      case NotificationChannelType.EMAIL:
        return {
          to: users.map((u) => u.email),
          subject: data.title,
          body: data.message,
        } as ChannelPayloadMap[K];

      case NotificationChannelType.SMS:
        return {
          to: users.map((u) => u.phone),
          message: data.message,
        } as ChannelPayloadMap[K];

      case NotificationChannelType.PUSH:
        return {
          to: users.map((u) => u.deviceToken!).filter(Boolean),
          title: data.title,
          body: data.message,
        } as ChannelPayloadMap[K];
    }
  }
}

// SRP: Orchestrates notification flow ONLY
// DIP: Depends on repository abstraction, not implementation
class NotificationService {
  constructor(private preferenceRepo: NotificationPreferenceRepository) {}

  // High-level API → used by controllers / event handlers
  async notifyUsers(
    users: User[],
    data: { title: string; message: string },
  ): Promise<void> {
    for (const user of users) {
      // DIP: Fetch preferences via abstraction
      const channels = await this.preferenceRepo.getUserPreferences(user.id);

      await this.notifyUser(user, channels, data);
    }
  }

  // SRP: Handles per-user logic
  private async notifyUser(
    user: User,
    channels: NotificationChannelType[],
    data: { title: string; message: string },
  ) {
    // Parallel execution → better performance (real-world thinking)
    const tasks = channels.map((channelType) =>
      this.sendViaChannel(channelType, [user], data),
    );

    await Promise.all(tasks);
  }

  // STRATEGY + FACTORY usage
  private async sendViaChannel<K extends NotificationChannelType>(
    type: K,
    users: User[],
    data: { title: string; message: string },
  ) {
    // Factory resolves correct strategy implementation
    const channel = NotificationChannelFactory.getChannel(type);

    // Builder transforms domain → channel-specific payload
    const payload = NotificationPayloadBuilder.build(type, users, data);

    // Polymorphism (LSP): All channels behave uniformly
    await channel.send(payload);
  }
}
