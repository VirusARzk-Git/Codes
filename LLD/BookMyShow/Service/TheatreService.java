package BookMyShow.Service;

import java.time.LocalDate;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import BookMyShow.Entities.Movie;
import BookMyShow.Entities.Show;
import BookMyShow.Entities.Theatre;
import BookMyShow.Enums.City;

public class TheatreService {
    private final Map<City, List<Theatre>> cityTheatres = new HashMap<>();

    public void addTheatre(Theatre theatre) {
        cityTheatres.computeIfAbsent(theatre.getCity(), k -> new java.util.ArrayList<>()).add(theatre);
    }

    public List<Theatre> getTheatresByCity(City city, Movie movie, LocalDate date) {
        List<Theatre> theatres = cityTheatres.getOrDefault(city, new java.util.ArrayList<>());

        return theatres.stream()
                .filter(t -> t.getScreens().stream()
                        .anyMatch(screen -> screen.getShowsByDate(date).stream()
                                .anyMatch(show -> show.getMovie().equals(movie))))
                .toList();
    }

    public List<Show> getShows(Movie movie, LocalDate date, Theatre theatre) {
        return theatre.getScreens().stream()
                .flatMap(screen -> screen.getShowsByDate(date).stream())
                .filter(show -> show.getMovie().equals(movie))
                .toList();
    }
}
