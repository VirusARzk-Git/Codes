package BookMyShow.Entities;

import BookMyShow.Enums.SeatCategory;

public class Seat {
    private final String seatId;
    private final SeatCategory category;

    public Seat(String seatId, SeatCategory category) {
        this.seatId = seatId;
        this.category = category;
    }

    public String getSeatId() {
        return seatId;
    }

    public SeatCategory getCategory() {
        return category;
    }
}
