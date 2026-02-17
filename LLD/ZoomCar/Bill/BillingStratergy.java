package ZoomCar.Bill;

import ZoomCar.Reservation.Reservation;

public interface BillingStratergy {
  Bill generateBill(Reservation reservation);
}
