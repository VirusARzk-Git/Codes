package BookMyShow;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

import BookMyShow.Controllers.BookingController;
import BookMyShow.Entities.Booking;
import BookMyShow.Entities.Movie;
import BookMyShow.Entities.Screen;
import BookMyShow.Entities.Seat;
import BookMyShow.Entities.Show;
import BookMyShow.Entities.Theatre;
import BookMyShow.Entities.User;
import BookMyShow.Enums.City;
import BookMyShow.Enums.SeatCategory;
import BookMyShow.Service.BookingService;
import BookMyShow.Service.TheatreService;

public class BookMyShow {

    private static final Scanner scanner = new Scanner(System.in);
    private static final TheatreService theatreService = new TheatreService();
    private static final BookingService bookingService = new BookingService();
    private static final BookingController bookingController = new BookingController(bookingService);
    
    private static final Map<String, Movie> movies = new HashMap<>();
    private static final Map<Integer, User> users = new HashMap<>();
    private static final List<Theatre> allTheatres = new ArrayList<>();
    private static User currentUser = null;

    public static void main(String[] args) {
        initializeSampleData();
        
        System.out.println("========================================");
        System.out.println("   Welcome to BookMyShow!");
        System.out.println("========================================");

        while (true) {
            showMainMenu();
            int choice = getIntInput("Enter your choice: ");

            switch (choice) {
                case 1 -> loginOrRegister();
                case 2 -> browseMoviesByCity();
                case 3 -> viewAllMovies();
                case 4 -> bookTickets();
                case 5 -> viewMyBookings();
                case 6 -> addNewTheatre();
                case 7 -> addNewMovie();
                case 8 -> addShowToTheatre();
                case 9 -> {
                    System.out.println("\nThank you for using BookMyShow! Goodbye!");
                    return;
                }
                default -> System.out.println("\nInvalid choice. Please try again.");
            }
        }
    }

    private static void showMainMenu() {
        System.out.println("\n========== MAIN MENU ==========");
        System.out.println("Current User: " + (currentUser != null ? currentUser.getName() : "Not logged in"));
        System.out.println("--------------------------------");
        System.out.println("1. Login / Register");
        System.out.println("2. Browse Movies by City");
        System.out.println("3. View All Movies");
        System.out.println("4. Book Tickets");
        System.out.println("5. View My Bookings");
        System.out.println("6. Add New Theatre (Admin)");
        System.out.println("7. Add New Movie (Admin)");
        System.out.println("8. Add Show to Theatre (Admin)");
        System.out.println("9. Exit");
        System.out.println("================================");
    }

    private static void loginOrRegister() {
        System.out.println("\n--- LOGIN / REGISTER ---");
        System.out.println("1. Login with existing User ID");
        System.out.println("2. Register new user");
        
        int choice = getIntInput("Choice: ");
        
        if (choice == 1) {
            int userId = getIntInput("Enter User ID: ");
            if (users.containsKey(userId)) {
                currentUser = users.get(userId);
                System.out.println("Welcome back, " + currentUser.getName() + "!");
            } else {
                System.out.println("User not found. Please register first.");
            }
        } else if (choice == 2) {
            int userId = users.size() + 1;
            System.out.print("Enter your name: ");
            String name = scanner.nextLine();
            User newUser = new User(userId, name);
            users.put(userId, newUser);
            currentUser = newUser;
            System.out.println("Registration successful! Your User ID is: " + userId);
        }
    }

    private static void browseMoviesByCity() {
        System.out.println("\n--- BROWSE MOVIES BY CITY ---");
        City city = selectCity();
        if (city == null) return;

        System.out.print("Enter date (yyyy-MM-dd) or press Enter for today: ");
        String dateStr = scanner.nextLine();
        LocalDate date = dateStr.isEmpty() ? LocalDate.now() : LocalDate.parse(dateStr);

        System.out.println("\nAvailable Movies in " + city + " on " + date + ":");
        System.out.println("-------------------------------------------");

        boolean found = false;
        for (Movie movie : movies.values()) {
            List<Theatre> theatres = theatreService.getTheatresByCity(city, movie, date);
            if (!theatres.isEmpty()) {
                found = true;
                System.out.println("\n>> " + movie.getName());
                for (Theatre theatre : theatres) {
                    System.out.println("   Theatre: " + theatre.getName());
                    List<Show> shows = theatreService.getShows(movie, date, theatre);
                    System.out.print("   Shows: ");
                    for (Show show : shows) {
                        System.out.print(show.getStartTime() + "  ");
                    }
                    System.out.println();
                }
            }
        }

        if (!found) {
            System.out.println("No movies available in " + city + " on " + date);
        }
    }

    private static void viewAllMovies() {
        System.out.println("\n--- ALL MOVIES ---");
        if (movies.isEmpty()) {
            System.out.println("No movies available.");
            return;
        }
        
        int i = 1;
        for (Movie movie : movies.values()) {
            System.out.println(i++ + ". " + movie.getName());
        }
    }

    private static void bookTickets() {
        if (currentUser == null) {
            System.out.println("\nPlease login first to book tickets!");
            return;
        }

        System.out.println("\n--- BOOK TICKETS ---");
        
        // Select City
        City city = selectCity();
        if (city == null) return;

        // Select Movie
        Movie movie = selectMovie();
        if (movie == null) return;

        // Select Date
        System.out.print("Enter date (yyyy-MM-dd) or press Enter for today: ");
        String dateStr = scanner.nextLine();
        LocalDate date = dateStr.isEmpty() ? LocalDate.now() : LocalDate.parse(dateStr);

        // Get theatres showing this movie
        List<Theatre> theatres = theatreService.getTheatresByCity(city, movie, date);
        if (theatres.isEmpty()) {
            System.out.println("No theatres showing " + movie.getName() + " in " + city + " on " + date);
            return;
        }

        // Select Theatre
        System.out.println("\nAvailable Theatres:");
        for (int i = 0; i < theatres.size(); i++) {
            System.out.println((i + 1) + ". " + theatres.get(i).getName());
        }
        int theatreChoice = getIntInput("Select theatre: ") - 1;
        if (theatreChoice < 0 || theatreChoice >= theatres.size()) {
            System.out.println("Invalid selection.");
            return;
        }
        Theatre selectedTheatre = theatres.get(theatreChoice);

        // Select Show
        List<Show> shows = theatreService.getShows(movie, date, selectedTheatre);
        System.out.println("\nAvailable Shows:");
        for (int i = 0; i < shows.size(); i++) {
            System.out.println((i + 1) + ". " + shows.get(i).getStartTime());
        }
        int showChoice = getIntInput("Select show: ") - 1;
        if (showChoice < 0 || showChoice >= shows.size()) {
            System.out.println("Invalid selection.");
            return;
        }
        Show selectedShow = shows.get(showChoice);

        // Display available seats
        System.out.println("\nAvailable Seats (Screen " + selectedShow.getScreen().getScreenId() + "):");
        displayAvailableSeats(selectedShow);

        // Select Seats
        System.out.print("Enter seat IDs to book (comma-separated, e.g., A1,A2,B3): ");
        String seatInput = scanner.nextLine();
        String[] seatIds = seatInput.split(",");
        
        List<Seat> selectedSeats = new ArrayList<>();
        Screen screen = selectedShow.getScreen();
        
        for (String seatId : seatIds) {
            seatId = seatId.trim();
            Seat seat = screen.getSeatById(seatId);
            if (seat != null) {
                selectedSeats.add(seat);
            } else {
                System.out.println("Seat " + seatId + " not found.");
            }
        }

        if (selectedSeats.isEmpty()) {
            System.out.println("No valid seats selected.");
            return;
        }

        // Confirm booking
        System.out.println("\n--- BOOKING SUMMARY ---");
        System.out.println("Movie: " + movie.getName());
        System.out.println("Theatre: " + selectedTheatre.getName());
        System.out.println("Date: " + date);
        System.out.println("Time: " + selectedShow.getStartTime());
        System.out.println("Seats: " + seatInput);
        System.out.print("\nConfirm booking? (y/n): ");
        
        String confirm = scanner.nextLine();
        if (confirm.equalsIgnoreCase("y")) {
            try {
                Booking booking = bookingController.createBooking(currentUser, selectedShow, selectedSeats);
                System.out.println("\n*** BOOKING SUCCESSFUL! ***");
                System.out.println("Booking ID: " + booking.getBookingId());
                System.out.println("Payment Status: " + booking.getPayment().getPaymentStatus());
            } catch (RuntimeException e) {
                System.out.println("\nBooking failed: " + e.getMessage());
            }
        } else {
            System.out.println("Booking cancelled.");
        }
    }

    private static void viewMyBookings() {
        if (currentUser == null) {
            System.out.println("\nPlease login first to view bookings!");
            return;
        }

        System.out.println("\n--- MY BOOKINGS ---");
        List<Booking> bookings = bookingController.getUserBookings(currentUser);
        
        if (bookings.isEmpty()) {
            System.out.println("You have no bookings.");
            return;
        }

        for (Booking booking : bookings) {
            System.out.println("--------------------------------");
            System.out.println("Booking ID: " + booking.getBookingId());
            System.out.println("Movie: " + booking.getShow().getMovie().getName());
            System.out.println("Date: " + booking.getShow().getShowDate());
            System.out.println("Time: " + booking.getShow().getStartTime());
            System.out.print("Seats: ");
            for (Seat seat : booking.getSeats()) {
                System.out.print(seat.getSeatId() + " ");
            }
            System.out.println();
            System.out.println("Payment Status: " + booking.getPayment().getPaymentStatus());
        }
        System.out.println("--------------------------------");
    }

    private static void addNewTheatre() {
        System.out.println("\n--- ADD NEW THEATRE (Admin) ---");
        
        System.out.print("Enter theatre name: ");
        String name = scanner.nextLine();
        
        City city = selectCity();
        if (city == null) return;
        
        int numScreens = getIntInput("Enter number of screens: ");
        List<Screen> screens = new ArrayList<>();
        
        for (int i = 0; i < numScreens; i++) {
            System.out.println("\nConfiguring Screen " + (i + 1) + ":");
            int numRows = getIntInput("  Number of rows: ");
            int seatsPerRow = getIntInput("  Seats per row: ");
            
            List<Seat> seats = createSeats(numRows, seatsPerRow);
            screens.add(new Screen(i + 1, seats));
        }
        
        Theatre theatre = new Theatre(name, city, screens);
        theatreService.addTheatre(theatre);
        allTheatres.add(theatre);
        
        System.out.println("\nTheatre '" + name + "' added successfully in " + city);
    }

    private static void addNewMovie() {
        System.out.println("\n--- ADD NEW MOVIE (Admin) ---");
        System.out.print("Enter movie name: ");
        String name = scanner.nextLine();
        
        if (movies.containsKey(name.toLowerCase())) {
            System.out.println("Movie already exists.");
            return;
        }
        
        Movie movie = new Movie(name);
        movies.put(name.toLowerCase(), movie);
        System.out.println("Movie '" + name + "' added successfully!");
    }

    private static void addShowToTheatre() {
        System.out.println("\n--- ADD SHOW TO THEATRE (Admin) ---");
        
        if (allTheatres.isEmpty()) {
            System.out.println("No theatres available. Please add a theatre first.");
            return;
        }
        
        if (movies.isEmpty()) {
            System.out.println("No movies available. Please add a movie first.");
            return;
        }
        
        // Select Theatre
        System.out.println("Available Theatres:");
        for (int i = 0; i < allTheatres.size(); i++) {
            System.out.println((i + 1) + ". " + allTheatres.get(i).getName() + " (" + allTheatres.get(i).getCity() + ")");
        }
        int theatreChoice = getIntInput("Select theatre: ") - 1;
        if (theatreChoice < 0 || theatreChoice >= allTheatres.size()) {
            System.out.println("Invalid selection.");
            return;
        }
        Theatre theatre = allTheatres.get(theatreChoice);
        
        // Select Screen
        List<Screen> screens = theatre.getScreens();
        System.out.println("\nAvailable Screens:");
        for (int i = 0; i < screens.size(); i++) {
            System.out.println((i + 1) + ". Screen " + (i + 1));
        }
        int screenChoice = getIntInput("Select screen: ") - 1;
        if (screenChoice < 0 || screenChoice >= screens.size()) {
            System.out.println("Invalid selection.");
            return;
        }
        Screen screen = screens.get(screenChoice);
        
        // Select Movie
        Movie movie = selectMovie();
        if (movie == null) return;
        
        // Enter Date and Time
        System.out.print("Enter show date (yyyy-MM-dd): ");
        String dateStr = scanner.nextLine();
        LocalDate date = LocalDate.parse(dateStr);
        
        System.out.print("Enter show time (HH:mm): ");
        String timeStr = scanner.nextLine();
        LocalTime time = LocalTime.parse(timeStr);
        
        Show show = new Show(movie, screen, date, time);
        screen.addShow(show);
        
        System.out.println("\nShow added successfully!");
        System.out.println("Movie: " + movie.getName());
        System.out.println("Theatre: " + theatre.getName());
        System.out.println("Screen: " + (screenChoice + 1));
        System.out.println("Date: " + date);
        System.out.println("Time: " + time);
    }

    // ========== HELPER METHODS ==========

    private static City selectCity() {
        System.out.println("\nSelect City:");
        City[] cities = City.values();
        for (int i = 0; i < cities.length; i++) {
            System.out.println((i + 1) + ". " + cities[i]);
        }
        int choice = getIntInput("Choice: ") - 1;
        if (choice < 0 || choice >= cities.length) {
            System.out.println("Invalid selection.");
            return null;
        }
        return cities[choice];
    }

    private static Movie selectMovie() {
        if (movies.isEmpty()) {
            System.out.println("No movies available.");
            return null;
        }
        
        System.out.println("\nSelect Movie:");
        List<Movie> movieList = new ArrayList<>(movies.values());
        for (int i = 0; i < movieList.size(); i++) {
            System.out.println((i + 1) + ". " + movieList.get(i).getName());
        }
        int choice = getIntInput("Choice: ") - 1;
        if (choice < 0 || choice >= movieList.size()) {
            System.out.println("Invalid selection.");
            return null;
        }
        return movieList.get(choice);
    }

    private static int getIntInput(String prompt) {
        System.out.print(prompt);
        while (!scanner.hasNextInt()) {
            System.out.print("Please enter a valid number: ");
            scanner.next();
        }
        int value = scanner.nextInt();
        scanner.nextLine(); // consume newline
        return value;
    }

    private static List<Seat> createSeats(int numRows, int seatsPerRow) {
        List<Seat> seats = new ArrayList<>();
        SeatCategory[] categories = {SeatCategory.SILVER, SeatCategory.GOLD, SeatCategory.PLATINUM};
        
        for (int row = 0; row < numRows; row++) {
            char rowChar = (char) ('A' + row);
            SeatCategory category = categories[Math.min(row / 3, categories.length - 1)];
            
            for (int seatNum = 1; seatNum <= seatsPerRow; seatNum++) {
                String seatId = rowChar + String.valueOf(seatNum);
                seats.add(new Seat(seatId, category));
            }
        }
        return seats;
    }

    private static void displayAvailableSeats(Show show) {
        System.out.println("(Format: SeatID [Category])");
        System.out.println();
        
        Screen screen = show.getScreen();
        for (Seat seat : screen.getSeats()) {
            System.out.print(seat.getSeatId() + "[" + seat.getCategory().toString().charAt(0) + "] ");
        }
        System.out.println("\n");
        System.out.println("Legend: S=Silver, G=Gold, P=Platinum");
    }

    private static void initializeSampleData() {
        // Add sample movies
        Movie movie1 = new Movie("Avengers: Endgame");
        Movie movie2 = new Movie("The Dark Knight");
        Movie movie3 = new Movie("Inception");
        movies.put("avengers: endgame", movie1);
        movies.put("the dark knight", movie2);
        movies.put("inception", movie3);

        // Create sample seats
        List<Seat> screen1Seats = createSeats(5, 10);
        List<Seat> screen2Seats = createSeats(4, 8);

        // Create screens
        Screen screen1 = new Screen(1, screen1Seats);
        Screen screen2 = new Screen(2, screen2Seats);

        // Create theatre
        Theatre theatre1 = new Theatre("PVR Cinemas", City.BANGALORE, List.of(screen1, screen2));
        theatreService.addTheatre(theatre1);
        allTheatres.add(theatre1);

        // Add shows
        LocalDate today = LocalDate.now();
        Show show1 = new Show(movie1, screen1, today, LocalTime.of(10, 0));
        Show show2 = new Show(movie1, screen1, today, LocalTime.of(14, 0));
        Show show3 = new Show(movie2, screen2, today, LocalTime.of(11, 0));
        Show show4 = new Show(movie3, screen2, today, LocalTime.of(18, 0));
        
        screen1.addShow(show1);
        screen1.addShow(show2);
        screen2.addShow(show3);
        screen2.addShow(show4);

        // Create another theatre in Delhi
        List<Seat> screen3Seats = createSeats(6, 12);
        Screen screen3 = new Screen(1, screen3Seats);
        Theatre theatre2 = new Theatre("INOX", City.DELHI, List.of(screen3));
        theatreService.addTheatre(theatre2);
        allTheatres.add(theatre2);

        Show show5 = new Show(movie1, screen3, today, LocalTime.of(15, 0));
        Show show6 = new Show(movie2, screen3, today, LocalTime.of(20, 0));
        screen3.addShow(show5);
        screen3.addShow(show6);

        // Add a sample user
        User sampleUser = new User(1, "Guest User");
        users.put(1, sampleUser);
    }
}
