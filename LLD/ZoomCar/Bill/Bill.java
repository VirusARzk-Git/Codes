package ZoomCar.Bill;

public class Bill {
    private int billID;
    private int reservationID;
    private int billAmount;
    private boolean isPaid;

    public Bill(int billID, int reservationID, int billAmount) {
        this.billID = billID;
        this.reservationID = reservationID;
        this.billAmount = billAmount;
        this.isPaid = false;
    }

    public int getBillID() {
        return billID;
    }

    public int getReservationID() {
        return reservationID;
    }

    public int getBillAmount() {
        return billAmount;
    }

    public boolean isPaid() {
        return isPaid;
    }

    public void setBillPaid(boolean paid) {
        isPaid = paid;
    }
}
