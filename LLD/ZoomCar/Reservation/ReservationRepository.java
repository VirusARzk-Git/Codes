package ZoomCar.Reservation;

import java.util.Map;
import java.util.Optional;
import java.util.concurrent.ConcurrentHashMap;

public class ReservationRepository {

  private final Map<Integer, Reservation> reservations;

  public ReservationRepository() {
    this.reservations = new ConcurrentHashMap<>();
  }

  public void addReservation(Reservation reservation) {
    reservations.put(reservation.getReservationId(), reservation);
  }

  public void removeReservation(int reservationId) {
    reservations.remove(reservationId);
  }

  // Lookup reservation by ID
  public Optional<Reservation> findById(int reservationId) {
    return Optional.ofNullable(reservations.get(reservationId));
  }
}
