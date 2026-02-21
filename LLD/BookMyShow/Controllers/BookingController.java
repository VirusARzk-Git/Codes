package BookMyShow.Controllers;

import java.util.List;

import BookMyShow.Entities.Booking;
import BookMyShow.Entities.Seat;
import BookMyShow.Entities.Show;
import BookMyShow.Entities.User;
import BookMyShow.Service.BookingService;

public class BookingController {
    private final BookingService bookingService;

    public BookingController(BookingService bookingService) {
        this.bookingService = bookingService;
    }

    public Booking createBooking(User user, Show show, List<Seat> seatIds) {
        return bookingService.book(user, show, seatIds);
    }

    public List<Booking> getUserBookings(User user) {
        return bookingService.getBookingsForUser(user);
    }
}
