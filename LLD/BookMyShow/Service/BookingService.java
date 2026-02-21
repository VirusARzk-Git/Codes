package BookMyShow.Service;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.UUID;

import BookMyShow.Entities.Booking;
import BookMyShow.Entities.Payment;
import BookMyShow.Entities.Seat;
import BookMyShow.Entities.Show;
import BookMyShow.Entities.User;
import BookMyShow.Enums.PaymentStatus;

public class BookingService {
    private final Map<UUID, Booking> bookings = new HashMap<>();

    public Booking book(User user, Show show, List<Seat> seats) {
        if(!show.lockSeats(seats)) {
            throw new RuntimeException("Seats are not available");
        }

        Payment payment = new Payment(PaymentStatus.SUCCESS);

        if(payment.getPaymentStatus() != PaymentStatus.SUCCESS) {
            show.releaseSeats(seats);
            throw new RuntimeException("Payment failed");
        }
        else{
            Booking booking = new Booking(user, show, seats, payment);
            bookings.put(booking.getBookingId(), booking);
            return booking;
        }
    }

    public Booking getBooking(UUID bookingId) {
        return bookings.get(bookingId);
    }

    public List<Booking> getBookingsForUser(User user) {
        return bookings.values().stream()
                .filter(booking -> booking.getUser().equals(user))
                .toList();
    }
}
