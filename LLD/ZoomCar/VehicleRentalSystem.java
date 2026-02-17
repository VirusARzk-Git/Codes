package ZoomCar;

import ZoomCar.Bill.Bill;
import ZoomCar.Bill.BillManager;
import ZoomCar.Bill.DailyBillingStratergy;
import ZoomCar.Payment.CardPaymentStratergy;
import ZoomCar.Payment.Payment;
import ZoomCar.Payment.PaymentManager;
import ZoomCar.Payment.PaymentStratergy;
import ZoomCar.Product.Vehicle;
import ZoomCar.Product.VehicleInventoryManager;
import ZoomCar.Reservation.Reservation;
import ZoomCar.Reservation.ReservationManager;
import java.time.LocalDate;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class VehicleRentalSystem {

  final VehicleInventoryManager inventory;
  private final ReservationManager reservationManager;
  private final BillManager billingManager;
  private final PaymentManager paymentManager;
  Map<Integer, User> users;

  public VehicleRentalSystem() {
    users = new HashMap<>();
    this.inventory = new VehicleInventoryManager();
    this.billingManager = new BillManager(new DailyBillingStratergy(inventory));
    this.paymentManager = new PaymentManager(new CardPaymentStratergy());
    this.reservationManager = new ReservationManager(inventory);
  }

  public void addUser(User user) {
    users.put(user.getUserID(), user);
  }

  public User getUser(int userId) {
    return users.get(userId);
  }

  public void removeUser(int userId) {
    users.remove(userId);
  }

  // Search for available vehicles
  public List<Vehicle> searchVehicles(LocalDate startDate, LocalDate endDate) {
    return inventory.getAvailableVehicles(startDate, endDate);
  }

  // Create a reservation
  public Reservation createReservation(
    User user,
    int vehicleId,
    LocalDate startDate,
    LocalDate endDate
  ) {
    return reservationManager.createReservation(
      vehicleId,
      user.getUserID(),
      startDate,
      endDate
    );
  }

  // Update reservation
  public void cancelReservation(int reservationId) {
    reservationManager.cancelReservation(reservationId);
  }

  // Billing and Payment
  public Bill generateBill(Reservation reservation) {
    return billingManager.generateBill(reservation);
  }

  public Payment makePayment(
    Bill bill,
    PaymentStratergy paymentStratergy,
    int amount
  ) {
    paymentManager.setPaymentStratergy(paymentStratergy);
    if (!bill.isPaid()) {
      throw new RuntimeException("Bill is not paid");
    }
    reservationManager.remove(bill.getReservationID());
    return paymentManager.makePayment(bill, amount);
  }
}
