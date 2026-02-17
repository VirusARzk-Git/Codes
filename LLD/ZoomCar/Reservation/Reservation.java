package ZoomCar.Reservation;

import java.time.LocalDate;

public class Reservation {
    private final int reservationId;
    private final int vehicleId;
    private final int userId;
    private final LocalDate startDate;
    private final LocalDate endDate;

    public Reservation(int reservationId, int vehicleId, int userID, LocalDate startDate, LocalDate endDate) {
        this.reservationId = reservationId;
        this.vehicleId = vehicleId;
        this.userId = userID;
        this.startDate = startDate;
        this.endDate = endDate;
    }

    public int getReservationId() {
        return reservationId;
    }

    public int getVehicleId() {
        return vehicleId;
    }

    public int getUserId() {
        return userId;
    }

    public LocalDate getStartDate() {
        return startDate;
    }

    public LocalDate getEndDate() {
        return endDate;
    }
}
