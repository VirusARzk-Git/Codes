package ZoomCar.Bill;

import java.time.temporal.ChronoUnit;
import java.util.concurrent.atomic.AtomicInteger;

import ZoomCar.Product.Vehicle;
import ZoomCar.Product.VehicleInventoryManager;
import ZoomCar.Reservation.Reservation;

public class DailyBillingStratergy implements BillingStratergy {

    VehicleInventoryManager vehicleInventoryManager;

    private final AtomicInteger billIDGenerator = new AtomicInteger(105);

    public DailyBillingStratergy(VehicleInventoryManager vehicleInventoryManager) {
        this.vehicleInventoryManager = vehicleInventoryManager;
    }
    
  @Override
  public Bill generateBill(Reservation reservation) {
    int days = (int) (ChronoUnit.DAYS.between(reservation.getStartDate(), reservation.getEndDate())) + 1;
    
    int vehicleID = reservation.getVehicleId();
    Vehicle vehicle = vehicleInventoryManager.getVehicle(vehicleID)
      .orElseThrow(() -> new RuntimeException("Vehicle not found"));
      
    int billAmount = (days * vehicle.getDailyRentalCost());
    return new Bill(billIDGenerator.getAndIncrement(), reservation.getReservationId(), billAmount);
  }
}
