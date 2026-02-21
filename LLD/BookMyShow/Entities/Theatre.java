package BookMyShow.Entities;

import java.util.List;
import java.util.Map;

import BookMyShow.Enums.City;

public class Theatre {
    private final String name;
    private final City city;
    private final List<Screen> screens;

    public Theatre(String name, City city, List<Screen> screens) {
        this.name = name;
        this.city = city;
        this.screens = screens;
    }

    public String getName() {
        return name;
    }

    public City getCity() {
        return city;
    }

    public List<Screen> getScreens() {
        return screens;
    }

    public Map<String, Seat> getSeatMap() {
        Map<String, Seat> seatMap = new java.util.HashMap<>();
        for (Screen screen : screens) {
            for (Seat seat : screen.getSeats()) {
                seatMap.put(seat.getSeatId(), seat);
            }
        }
        return seatMap;
    }

    public Seat getSeatById(String seatId) {
        return getSeatMap().get(seatId);
    }
}
