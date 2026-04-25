/*
Functional Requirements
-Parking lot has multiple floors
-Each floor has multiple slots
-Slot types:
    - Bike
    - Car
    - Truck
-Vehicles:
    - Bike
    - Car
    - Truck
-System should:
    -Park a vehicle
    -Unpark a vehicle
    -Assign appropriate slot
    -Generate ticket
    -Calculate fee (basic is fine)
*/

import { MinHeap } from "@datastructures-js/heap";

const VehicleType = {
  BIKE: "BIKE",
  CAR: "CAR",
  TRUCK: "TRUCK",
};

class User {
  id: string;
  name: string;
  balance: number;
  constructor(id: string, name: string, balance: number) {
    this.id = id;
    this.name = name;
    this.balance = balance;
  }
}

class Vehicle {
  id: string;
  type: keyof typeof VehicleType;
  plateNumber: string;
  user: User;
  constructor(
    id: string,
    type: keyof typeof VehicleType,
    plateNumber: string,
    user: User,
  ) {
    this.id = id;
    this.type = type;
    this.plateNumber = plateNumber;
    this.user = user;
  }
}

class Floor {
  id: string;
  slots: Slot[];
  floorNumber: number;
  constructor(id: string, slots: Slot[], floorNumber: number) {
    this.id = id;
    this.slots = slots;
    this.floorNumber = floorNumber;
  }
}

class Slot {
  id: string;
  type: keyof typeof VehicleType;
  isOccupied: boolean;
  constructor(id: string, type: keyof typeof VehicleType) {
    this.id = id;
    this.type = type;
    this.isOccupied = false;
  }
}

class ParkingLot {
  floors: Floor[];
  constructor(floors: Floor[]) {
    this.floors = floors;
  }
}

class Ticket {
  id: string;
  vehicle: Vehicle;
  slot: Slot;
  price: number;
  constructor(id: string, vehicle: Vehicle, slot: Slot, price: number) {
    this.id = id;
    this.vehicle = vehicle;
    this.slot = slot;
    this.price = price;
  }
}

function getRandomId(): string {
  return Math.random().toString(36).substring(2, 15);
}

interface SlotPriceCalculationStrategy {
  getSlotPrice(slotId: string): number | undefined;
}

class BasicSlotPriceCalculationService implements SlotPriceCalculationStrategy {
  slotPriceMap: Map<string, number>;
  parkingLot: ParkingLot;

  constructor(parkingLot: ParkingLot) {
    this.parkingLot = parkingLot;
    this.slotPriceMap = new Map();
    for (const floor of parkingLot.floors) {
      for (const slot of floor.slots) {
        switch (slot.type) {
          case VehicleType.BIKE:
            this.slotPriceMap.set(slot.id, 10 * floor.floorNumber);
            break;
          case VehicleType.CAR:
            this.slotPriceMap.set(slot.id, 20 * floor.floorNumber);
            break;
          case VehicleType.TRUCK:
            this.slotPriceMap.set(slot.id, 30 * floor.floorNumber);
            break;
          default:
            throw new Error("Invalid vehicle type");
        }
      }
    }
  }

  getSlotPrice(slotId: string): number | undefined {
    return this.slotPriceMap.get(slotId);
  }
}

interface SlotAllocationStrategy {
  allocateSlot(vehicle: Vehicle): Slot;
  deallocateSlot(slot: Slot): void;
}

class CheapestSlotAllocationStrategy implements SlotAllocationStrategy {
  parkingLot: ParkingLot;
  vehicleToSlotMap: Map<keyof typeof VehicleType, MinHeap<Slot>>;
  priceCalculationStrategy: SlotPriceCalculationStrategy;

  constructor(
    parkingLot: ParkingLot,
    priceCalculationStrategy: SlotPriceCalculationStrategy,
  ) {
    this.parkingLot = parkingLot;
    this.priceCalculationStrategy = priceCalculationStrategy;
    this.vehicleToSlotMap = new Map<keyof typeof VehicleType, MinHeap<Slot>>();
    for (const type of Object.values(VehicleType)) {
      this.vehicleToSlotMap.set(
        type as keyof typeof VehicleType,
        new MinHeap<Slot>(
          (x) => this.priceCalculationStrategy.getSlotPrice(x.id)!,
        ),
      );
    }

    for (const floor of this.parkingLot.floors) {
      for (const slot of floor.slots) {
        if(!slot.isOccupied) {
          this.vehicleToSlotMap.get(slot.type)?.push(slot);
        }
      }
    }
  }

  allocateSlot(vehicle: Vehicle): Slot {
    const user = vehicle.user;
    const vehicleType = vehicle.type;

    if (!this.vehicleToSlotMap.has(vehicleType)) {
      throw new Error("Invalid vehicle type");
    }
    if (this.vehicleToSlotMap.get(vehicleType)!.size() === 0) {
      throw new Error("No available slot found");
    }

    const cheapestSlot = this.vehicleToSlotMap.get(vehicleType)!.top()!;

    if (
      user.balance <
      this.priceCalculationStrategy.getSlotPrice(cheapestSlot.id)!
    ) {
      throw new Error("Insufficient balance");
    }
    this.vehicleToSlotMap.get(vehicleType)?.pop();
    cheapestSlot.isOccupied = true;

    return cheapestSlot;
  }

  deallocateSlot(slot: Slot): void {
    this.vehicleToSlotMap.get(slot.type)?.push(slot);
    slot.isOccupied = false;
  }
}

class TicketRepository {
  tickets: Ticket[];
  constructor() {
    this.tickets = [];
  }

  createTicket(vehicle: Vehicle, slot: Slot, price: number): Ticket {
    const ticket = new Ticket(getRandomId(), vehicle, slot, price);
    this.tickets.push(ticket);
    return ticket;
  }

  getTicket(id: string): Ticket | undefined {
    return this.tickets.find((ticket) => ticket.id === id);
  }

  removeTicket(id: string): void {
    this.tickets = this.tickets.filter((ticket) => ticket.id !== id);
  }
}

class TicketService {
  ticketRepository: TicketRepository;
  priceCalculationStrategy: SlotPriceCalculationStrategy;
  constructor(ticketRepository: TicketRepository, priceCalculationStrategy: SlotPriceCalculationStrategy) {
    this.priceCalculationStrategy = priceCalculationStrategy;
    this.ticketRepository = ticketRepository;
  }
    
  createTicket(vehicle: Vehicle, slot: Slot): Ticket {
    const price = this.priceCalculationStrategy.getSlotPrice(slot.id)!;
    return this.ticketRepository.createTicket(vehicle, slot, price);
  }

  getTicket(id: string): Ticket | undefined {
    return this.ticketRepository.getTicket(id);
  }

  removeTicket(id: string): void {
    this.ticketRepository.removeTicket(id);
  }
}

class ParkingLotService {
  parkingLot: ParkingLot;
  ticketService: TicketService;
  slotAllocationStrategy: SlotAllocationStrategy;
  constructor(parkingLot: ParkingLot, ticketService: TicketService, slotAllocationStrategy: SlotAllocationStrategy) {
    this.parkingLot = parkingLot;
    this.ticketService = ticketService;
    this.slotAllocationStrategy = slotAllocationStrategy;
  }

  parkVehicle(vehicle: Vehicle): Ticket {
    
    const slot = this.slotAllocationStrategy.allocateSlot(vehicle);

    return this.ticketService.createTicket(vehicle, slot);
  }

  unparkVehicle(ticketId: string): void {
    const ticket = this.ticketService.getTicket(ticketId);
    if (!ticket) {
      throw new Error("Ticket not found");
    }
    this.slotAllocationStrategy.deallocateSlot(ticket.slot);
    this.ticketService.removeTicket(ticketId);
    return;
  }
}

function main() {
    const user = new User(getRandomId(), "John Doe", 100);
    const vehicle = new Vehicle(getRandomId(), VehicleType.BIKE as keyof typeof VehicleType, "1234567890", user);

    const floors: Floor[] = []

    for(let i=0; i<3; i++) {
        const slots: Slot[] = []
        for(let j= 0; j<5; j++) {
            slots.push(new Slot(getRandomId(), VehicleType.BIKE as keyof typeof VehicleType));
            slots.push(new Slot(getRandomId(), VehicleType.CAR as keyof typeof VehicleType));
            slots.push(new Slot(getRandomId(), VehicleType.TRUCK as keyof typeof VehicleType));
        }
        floors.push(new Floor(getRandomId(), slots, i+1));
    }
  const parkingLot = new ParkingLot(floors);

  const ticketService = new TicketService(new TicketRepository(), new BasicSlotPriceCalculationService(parkingLot));

  const parkingLotService = new ParkingLotService(parkingLot, ticketService, new CheapestSlotAllocationStrategy(parkingLot, new BasicSlotPriceCalculationService(parkingLot)));

  const ticket = parkingLotService.parkVehicle(vehicle);
  console.log(ticket);
  parkingLotService.unparkVehicle(ticket.id);
  console.log(ticket);
}

main();
