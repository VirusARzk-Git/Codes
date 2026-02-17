package ZoomCar.Bill;

import ZoomCar.Reservation.Reservation;
import java.util.Map;
import java.util.Optional;
import java.util.concurrent.ConcurrentHashMap;

public class BillManager {

  private BillingStratergy billingStratergy;

  // store all the bills here
  private final Map<Integer, Bill> bills = new ConcurrentHashMap<>();

  public BillManager(BillingStratergy billingStratergy) {
    this.billingStratergy = billingStratergy;
  }

  public Bill generateBill(Reservation reservation) {
    Bill bill = billingStratergy.generateBill(reservation);
    bills.put(bill.getBillID(), bill);
    return bill;
  }

  public Optional<Bill> getBill(int billId) {
    return Optional.ofNullable(bills.get(billId));
  }

  public void updateBillingStratergy(BillingStratergy billingStratergy) {
    this.billingStratergy = billingStratergy;
  }
}
