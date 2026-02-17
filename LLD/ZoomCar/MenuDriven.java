package ZoomCar;

import ZoomCar.Bill.Bill;
import ZoomCar.Product.Vehicle;
import ZoomCar.Product.VehicleType;
import ZoomCar.Reservation.Reservation;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.atomic.AtomicInteger;

public class MenuDriven {

  static AtomicInteger userIdGenerator = new AtomicInteger(8);
  static AtomicInteger vehicleIdGenerator = new AtomicInteger(2341);
  static DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");

  public static void main(String[] args) {
    System.out.println("Welcome to ZoomCar!\n");

    VehicleRentalSystem rentalSystem = new VehicleRentalSystem();
    seedData(rentalSystem);
    Scanner sc = new Scanner(System.in);

    boolean running = true;
    while (running) {
      System.out.println("\n===== MENU =====");
      System.out.println("1. Add User");
      System.out.println("2. Add Vehicle");
      System.out.println("3. Search Vehicles");
      System.out.println("4. Book a Vehicle");
      System.out.println("5. Cancel Reservation");
      System.out.println("6. Exit");
      System.out.print("Enter choice: ");
      int choice = sc.nextInt();
      sc.nextLine();

      switch (choice) {
        case 1:
          addUser(sc, rentalSystem);
          break;
        case 2:
          addVehicle(sc, rentalSystem);
          break;
        case 3:
          searchVehicles(sc, rentalSystem);
          break;
        case 4:
          bookVehicle(sc, rentalSystem);
          break;
        case 5:
          cancelReservation(sc, rentalSystem);
          break;
        case 6:
          running = false;
          System.out.println("Exiting ZoomCar. Goodbye!");
          break;
        default:
          System.out.println("Invalid choice. Try again.");
      }
    }
    sc.close();
  }

  // Pre-populate sample data
  private static void seedData(VehicleRentalSystem rentalSystem) {
    // Users
    User u1 = new User(userIdGenerator.getAndIncrement(), "Rahul", "DL-14012345");
    User u2 = new User(userIdGenerator.getAndIncrement(), "Priya", "MH-03254609");
    User u3 = new User(userIdGenerator.getAndIncrement(), "Amit", "KA-05204321");
    rentalSystem.addUser(u1);
    rentalSystem.addUser(u2);
    rentalSystem.addUser(u3);

    // Vehicles
    Vehicle v1 = new Vehicle(vehicleIdGenerator.getAndIncrement(), "MH12AB1234", VehicleType.FOUR_WHEELER, 1500);
    Vehicle v2 = new Vehicle(vehicleIdGenerator.getAndIncrement(), "KA05CD5678", VehicleType.FOUR_WHEELER, 2000);
    Vehicle v3 = new Vehicle(vehicleIdGenerator.getAndIncrement(), "DL14EF9012", VehicleType.TWO_WHEELER, 500);
    Vehicle v4 = new Vehicle(vehicleIdGenerator.getAndIncrement(), "MH04GH3456", VehicleType.TWO_WHEELER, 600);
    Vehicle v5 = new Vehicle(vehicleIdGenerator.getAndIncrement(), "KA01JK7890", VehicleType.FOUR_WHEELER, 2500);
    rentalSystem.inventory.addVehicle(v1);
    rentalSystem.inventory.addVehicle(v2);
    rentalSystem.inventory.addVehicle(v3);
    rentalSystem.inventory.addVehicle(v4);
    rentalSystem.inventory.addVehicle(v5);
  }

  // 1. Add User
  private static void addUser(Scanner sc, VehicleRentalSystem rentalSystem) {
    System.out.print("Enter user name: ");
    String name = sc.nextLine();
    System.out.print("Enter driving license number: ");
    String license = sc.nextLine();

    int id = userIdGenerator.getAndIncrement();
    User user = new User(id, name, license);
    rentalSystem.addUser(user);
    System.out.println("User added with ID: " + id);
  }

  // 2. Add Vehicle
  private static void addVehicle(Scanner sc, VehicleRentalSystem rentalSystem) {
    System.out.print("Enter vehicle number (e.g. MH12ZP6889): ");
    String vehicleNumber = sc.nextLine();

    System.out.print("Enter daily rental cost: ");
    int cost = sc.nextInt();
    sc.nextLine();

    System.out.println("Select vehicle type:");
    System.out.println("1. FOUR_WHEELER");
    System.out.println("2. TWO_WHEELER");
    System.out.print("Enter choice (1 or 2): ");
    int typeChoice = sc.nextInt();
    VehicleType type = (typeChoice == 1) ? VehicleType.FOUR_WHEELER : VehicleType.TWO_WHEELER;

    int id = vehicleIdGenerator.getAndIncrement();
    Vehicle vehicle = new Vehicle(id, vehicleNumber, type, cost);
    rentalSystem.inventory.addVehicle(vehicle);
    System.out.println("Vehicle added with ID: " + id);
  }

  private static LocalDate from;
  private static LocalDate to;

  // 3. Search Vehicles
  private static List<Vehicle> searchVehicles(Scanner sc, VehicleRentalSystem rentalSystem) {
    System.out.print("Enter start date (DD-MM-YYYY): ");
    from = LocalDate.parse(sc.nextLine(), formatter);
    System.out.print("Enter number of days: ");
    int days = sc.nextInt();
    to = from.plusDays(days);

    List<Vehicle> available = rentalSystem.searchVehicles(from, to);

    if (available.isEmpty()) {
      System.out.println("No vehicles available for the selected dates.");
    } else {
      System.out.println("\nAvailable vehicles from " + from + " to " + to + ":");
      for (Vehicle v : available) {
        System.out.println("  ID: " + v.getVehicleID()
            + " | Number: " + v.getVehicleNumber()
            + " | Type: " + v.getVehicleType()
            + " | Cost/day: " + v.getDailyRentalCost());
      }
    }
    return available;
  }

  // 4. Book a Vehicle (search -> select -> reserve -> bill)
  private static void bookVehicle(Scanner sc, VehicleRentalSystem rentalSystem) {
    // Step 1: Search available vehicles
    List<Vehicle> available = searchVehicles(sc, rentalSystem);
    if (available.isEmpty()) return;

    // Step 2: Select vehicle and user
    System.out.print("\nEnter Vehicle ID to book: ");
    int vehicleId = sc.nextInt();
    System.out.print("Enter your User ID: ");
    int userId = sc.nextInt();
    sc.nextLine();

    User user = rentalSystem.getUser(userId);
    if (user == null) {
      System.out.println("User not found with ID: " + userId);
      return;
    }

    // Step 3: Create Reservation
    Reservation reservation = rentalSystem.createReservation(user, vehicleId, from, to);
    System.out.println("Reservation created with ID: " + reservation.getReservationId());

    // Step 4: Generate Bill
    Bill bill = rentalSystem.generateBill(reservation);
    System.out.println("Bill generated | Amount: " + bill.getBillAmount());
  }

  private static void cancelReservation(Scanner sc, VehicleRentalSystem rentalSystem) {
    System.out.print("Enter Reservation ID to cancel: ");
    int reservationId = sc.nextInt();
    sc.nextLine();

    try {
      rentalSystem.cancelReservation(reservationId);
      System.out.println("Reservation cancelled successfully.");
    } catch (RuntimeException e) {
      System.out.println(e.getMessage());
    }
  }
}
