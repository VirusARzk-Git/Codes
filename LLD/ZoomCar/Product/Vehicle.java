package ZoomCar.Product;

public class Vehicle {

  private final int vehicleID;
  private final String vehicleNumber;
  private final VehicleType vehicleType;
  private int dailyRentalCost;
  private VehicleStatus status;

  // int hourlyRentalCost;
  // int monthlyRentalCost;

  public Vehicle(
    int vehicleID,
    String vehicleNumber,
    VehicleType vehicleType,
    int dailyRentalCost
  ) {
    this.vehicleID = vehicleID;
    this.vehicleNumber = vehicleNumber;
    this.vehicleType = vehicleType;
    this.dailyRentalCost = dailyRentalCost;
    this.status = VehicleStatus.AVAILABLE;
  }

  // Getters

  public int getVehicleID() {
    return vehicleID;
  }

  public String getVehicleNumber() {
    return vehicleNumber;
  }

  public VehicleType getVehicleType() {
    return vehicleType;
  }

  public int getDailyRentalCost() {
    return dailyRentalCost;
  }

  public VehicleStatus getStatus() {
    return status;
  }

  // Setters
  public void setDailyRentalCost(int dailyRentalCost) {
    this.dailyRentalCost = dailyRentalCost;
  }

  public void setStatus(VehicleStatus status) {
    this.status = status;
  }
}
