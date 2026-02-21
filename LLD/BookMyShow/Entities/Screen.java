package BookMyShow.Entities;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Screen {
    private final int screenId;
    private final List<Seat> seats;
    private final Map<LocalDate, List<Show>> showsByDate = new HashMap<>();

    public Screen(int screenId, List<Seat> seats) {
        this.screenId = screenId;
        this.seats = seats;
    }

    public List<Seat> getSeats() {
        return seats;
    }

    public void addShow(Show show) {
        showsByDate.computeIfAbsent(show.getShowDate(), k -> new ArrayList<>()).add(show);
    }

    public List<Show> getShowsByDate(LocalDate date) {
        return showsByDate.getOrDefault(date, new ArrayList<>());
    }

    public Seat getSeatById(String seatId) {
        return seats.stream()
                .filter(seat -> seat.getSeatId().equals(seatId))
                .findFirst()
                .orElse(null);
    }

    public int getScreenId() {
        return screenId;
    }
}
