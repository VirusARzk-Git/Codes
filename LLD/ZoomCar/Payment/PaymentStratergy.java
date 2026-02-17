package ZoomCar.Payment;

import ZoomCar.Bill.Bill;

public interface PaymentStratergy {
    Payment processPayment(Bill bill, int amount);
}
