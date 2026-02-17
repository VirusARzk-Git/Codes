package ZoomCar.Payment;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

import ZoomCar.Bill.Bill;

public class PaymentManager {
    private PaymentStratergy paymentStratergy;
    private final Map<Integer, Payment> payments = new ConcurrentHashMap<>();

    public PaymentManager(PaymentStratergy paymentStratergy) {
        this.paymentStratergy = paymentStratergy;
    }

    public Payment makePayment(Bill bill, int amount) {
        Payment payment = paymentStratergy.processPayment(bill, amount);
        payments.put(payment.getPaymentId(), payment);
        return payment;
    }

    public void setPaymentStratergy(PaymentStratergy paymentStratergy) {
        this.paymentStratergy = paymentStratergy;
    }
}
