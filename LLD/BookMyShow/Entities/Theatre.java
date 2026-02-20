package BookMyShow.Entities;

import java.util.List;

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

    
}
