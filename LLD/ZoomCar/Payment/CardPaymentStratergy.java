package ZoomCar.Payment;

import java.util.concurrent.atomic.AtomicInteger;

import ZoomCar.Bill.Bill;

public class CardPaymentStratergy implements PaymentStratergy {

    private final AtomicInteger paymentIdGenerator = new AtomicInteger(102335413);
    
    @Override
    public Payment processPayment(Bill bill, int amount) {
        Payment payment = new Payment(paymentIdGenerator.getAndIncrement(), bill.getBillID(), amount, PaymentMode.CARD, new java.sql.Date(System.currentTimeMillis()));

        bill.setBillPaid(true);
        return payment;
    }
    
}
