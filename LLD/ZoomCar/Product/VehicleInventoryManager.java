package ZoomCar.Product;

import ZoomCar.Reservation.Reservation;
import ZoomCar.Reservation.ReservationRepository;
import java.time.LocalDate;
import java.util.List;
import java.util.Optional;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;

public class VehicleInventoryManager {

  // vehicleId to Vehicle mapping
  private final ConcurrentMap<Integer, Vehicle> vehicles = new ConcurrentHashMap<>();

  // vehicleId -> list of reservations
  private final ConcurrentMap<Integer, List<Integer>> vehicleBookingIDs = new ConcurrentHashMap<>();

  private ReservationRepository reservationRepository;

  public void addVehicle(Vehicle vehicle) {
    vehicles.put(vehicle.getVehicleID(), vehicle);
  }

  public Optional<Vehicle> getVehicle(int vehicleID) {
    return Optional.ofNullable(vehicles.get(vehicleID));
  }

  public void setReservationRepository(
    ReservationRepository reservationRepository
  ) {
    this.reservationRepository = reservationRepository;
  }

  // Availability check
  public boolean isVehicleAvailable(
    int vehicleID,
    LocalDate from,
    LocalDate to
  ) {
    Vehicle vehicle = vehicles.get(vehicleID);
    if (vehicle == null) {
      return false;
    }

    if (vehicle.getStatus() == VehicleStatus.MAINTENANCE) {
      return false;
    }

    DateInterval requestedInterval = new DateInterval(from, to);

    List<Integer> reservationIDs = vehicleBookingIDs.get(vehicleID);

    if (reservationIDs == null || reservationIDs.isEmpty()) {
      return true;
    }

    for (int reservationID : reservationIDs) {
      Optional<Reservation> reservationOpt = reservationRepository.findById(reservationID);
      if (reservationOpt.isEmpty()) {
        continue;
      }
      Reservation reservation = reservationOpt.get();
      LocalDate bookedFrom = reservation.getStartDate();
      LocalDate bookedTo = reservation.getEndDate();
      DateInterval bookedInterval = new DateInterval(bookedFrom, bookedTo);
      if (bookedInterval.overlaps(requestedInterval)) {
        return false;
      }
    }
    return true;
  }

  // Search
  public List<Vehicle> getAvailableVehicles(LocalDate from, LocalDate to) {
    return vehicles
      .values()
      .stream()
      .filter(v -> isVehicleAvailable(v.getVehicleID(), from, to))
      .toList();
  }

  public void addReservation(int vehicleID, int reservationID) {
    vehicleBookingIDs.computeIfAbsent(vehicleID, k -> new java.util.ArrayList<>()).add(reservationID);
  }

  public void removeReservation(int vehicleId, int reservationID) {
    List<Integer> reservationList = vehicleBookingIDs.get(vehicleId);
    if (reservationList != null) {
      reservationList.remove(Integer.valueOf(reservationID));
      if (reservationList.isEmpty()) {
        vehicleBookingIDs.remove(vehicleId);
      }
    }
  }
}
