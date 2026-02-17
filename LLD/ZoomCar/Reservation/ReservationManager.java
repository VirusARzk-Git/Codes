package ZoomCar.Reservation;

import ZoomCar.Product.VehicleInventoryManager;
import java.time.LocalDate;
import java.util.Optional;
import java.util.concurrent.atomic.AtomicInteger;

public class ReservationManager {

  private final VehicleInventoryManager inventory;
  private final ReservationRepository reservationRepository;

  private final AtomicInteger reservationIDGenerator = new AtomicInteger(
    325411
  );

  public ReservationManager(VehicleInventoryManager inventory) {
    this.inventory = inventory;
    this.reservationRepository = new ReservationRepository();
    this.inventory.setReservationRepository(this.reservationRepository);
  }

  // Get Reservation by ID
  public Optional<Reservation> getReservation(int reservationID) {
    return reservationRepository.findById(reservationID);
  }

  // Create a new reservation
  public Reservation createReservation(
    int vehicleID,
    int userID,
    LocalDate startDate,
    LocalDate endDate
  ) {
    int reservationID = reservationIDGenerator.getAndIncrement();
    Reservation reservation = new Reservation(
      reservationID,
      vehicleID,
      userID,
      startDate,
      endDate
    );
    inventory.addReservation(vehicleID, reservationID);
    reservationRepository.addReservation(reservation);
    return reservation;
  }

  // Cancel a reservation
  public void cancelReservation(int reservationID) {
    Optional<Reservation> reservation = reservationRepository.findById(
      reservationID
    );
    if (reservation.isPresent()) {
      reservationRepository.removeReservation(reservationID);
        inventory.removeReservation(reservation.get().getVehicleId(), reservationID);
    } else {
      throw new RuntimeException("Reservation not found");
    }
  }

  // remove reservation from vehicle booking list
  public void remove(int reservationID) {
    reservationRepository.removeReservation(reservationID);
  }
}
