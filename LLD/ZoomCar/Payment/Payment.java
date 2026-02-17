package ZoomCar.Payment;

import java.sql.Date;

public class Payment {
    private final int paymentId;
    private final int billId;
    private final int amountPaid;
    private final PaymentMode paymentMode;
    private final Date paymentDate;

    public Payment(int paymentId, int billId, int amountPaid, PaymentMode paymentMode, Date paymentDate) {
        this.paymentId = paymentId;
        this.billId = billId;
        this.amountPaid = amountPaid;
        this.paymentMode = paymentMode;
        this.paymentDate = paymentDate;
    }

    public int getPaymentId() {
        return paymentId;
    }

    public int getBillId() {
        return billId;
    }

    public int getAmountPaid() {
        return amountPaid;
    }

    public PaymentMode getPaymentMode() {
        return paymentMode;
    }

    public Date getPaymentDate() {
        return paymentDate;
    }
}
