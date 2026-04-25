/*
LLD Problem: Design a Rate Limiter
Functional Requirements
Limit number of requests per user
Example:
100 requests per minute per user
If limit exceeded → reject request

Clarifications (assume unless you ask)
In-memory implementation is fine
Single node (no distributed system needed)
Multiple algorithms should be supported:
Fixed Window
Sliding Window
Token Bucket

-----------------------------------------------

Follow this structure:

1. Core Entities
What are the main objects?
2. Interfaces (IMPORTANT)
Where will you introduce abstraction?
3. Algorithm Design

Pick at least one:

Fixed Window (simplest)
Sliding Window (better)
Token Bucket (best)
4. Class Design
Key classes + responsibilities
5. Flow
What happens when a request comes?
6. Extensibility
How will you support multiple algorithms?
⚠️ Evaluation Criteria

I’ll judge based on:

SOLID usage
Correct abstraction (Strategy pattern expected)
Edge case handling
Clean separation of concerns
Time complexity awareness
*/

interface StorageService<T> {
  save(key: string, value: T): void;
  get(key: string): T | null;
}

class InMemoryStorageService<T> implements StorageService<T> {
  private store = new Map<string, T>();

  save(key: string, value: T): void {
    this.store.set(key, value);
  }

  get(key: string): T | null {
    return this.store.get(key) || null;
  }
}

interface RateLimiterStrategy {
  isAllowed(userId: string): boolean;
}

type FixedWindowStorageData = { count: number; windowStart: number };

class FixedWindowRateLimiter implements RateLimiterStrategy {
  storage: StorageService<FixedWindowStorageData>;
  windowSize: number;
  maxRequests: number;

  constructor(storage: StorageService<FixedWindowStorageData>, windowSize: number = 1 * 60 * 1000, maxRequests: number = 100) {
    this.storage = storage;
    this.windowSize = windowSize;
    this.maxRequests = maxRequests;
  }

  isAllowed(userId: string): boolean {
    if (this.storage.get(userId)) {
      const { count, windowStart } = this.storage.get(userId)!;

      if (Date.now() - windowStart >= this.windowSize) {
        this.storage.save(userId, { count: 1, windowStart: Date.now() });
        return true;
      } else {
        if (count >= this.maxRequests) {
          return false;
        } else {
          this.storage.save(userId, { count: count + 1, windowStart });
          return true;
        }
      }
    } else {
      this.storage.save(userId, { count: 1, windowStart: Date.now() });
      return true;
    }
  }
}

class RateLimiterService {
    private strategy: RateLimiterStrategy;
    constructor(strategy: RateLimiterStrategy) {
        this.strategy = strategy;
    }

    isAllowed(userId: string): boolean {
        return this.strategy.isAllowed(userId);
    }
}

const rl: RateLimiterService = new RateLimiterService(new FixedWindowRateLimiter(
    new InMemoryStorageService<FixedWindowStorageData>(),
    1 * 60 * 1000,
    100
));
