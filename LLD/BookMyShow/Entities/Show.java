package BookMyShow.Entities;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import BookMyShow.Enums.SeatStatus;

public class Show {
    private final Movie movie;
    private final LocalDate showDate;
    private final LocalTime startTime;
    private final Screen screen;

    private final Map<Seat, SeatStatus> seatStatusMap = new HashMap<>();

    public Show(Movie movie, Screen screen, LocalDate showDate, LocalTime startTime) {
        this.movie = movie;
        this.showDate = showDate;
        this.startTime = startTime;
        this.screen = screen;

        for(Seat seat : screen.getSeats()) {
            seatStatusMap.put(seat, SeatStatus.AVAILABLE);
        }
    }

    public LocalDate getShowDate() {
        return showDate;
    }

    public Movie getMovie() {
        return movie;
    }

    public LocalTime getStartTime() {
        return startTime;
    }

    public Screen getScreen() {
        return screen;
    }

    public boolean lockSeats(List<Seat> seats) {
        for (Seat seat : seats) {
            if (seatStatusMap.get(seat) != SeatStatus.AVAILABLE) {
                return false;
            }
        }
        for (Seat seat : seats) {
            seatStatusMap.put(seat, SeatStatus.LOCKED);
        }
        return true;
    }

    public void confirmSeats(List<Seat> seats) {
        for (Seat seat : seats) {
            seatStatusMap.put(seat, SeatStatus.BOOKED);
        }
    }

    public void releaseSeats(List<Seat> seats) {
        for (Seat seat : seats) {
            seatStatusMap.put(seat, SeatStatus.AVAILABLE);
        }
    }

}
