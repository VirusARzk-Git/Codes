package BookMyShow.Entities;

import java.util.UUID;
import BookMyShow.Enums.PaymentStatus;

public class Payment {
    private final UUID paymentId;
    private final PaymentStatus paymentStatus;

    public Payment(PaymentStatus paymentStatus) {
        this.paymentId = UUID.randomUUID();
        this.paymentStatus = paymentStatus;
    }

    public UUID getPaymentId() {
        return paymentId;
    }

    public PaymentStatus getPaymentStatus() {
        return paymentStatus;
    }
}
