package ZoomCar.Product;

import java.time.LocalDate;

public class DateInterval {
    private final LocalDate from;
    private final LocalDate to;

    public DateInterval(LocalDate from, LocalDate to) {
        if(from.isAfter(to)) {
            throw new IllegalArgumentException("End date cannot be before Start date");
        }
        this.from = from;
        this.to = to;
    }

    public LocalDate getFrom() {
        return from;
    }

    public LocalDate getTo() {
        return to;
    }
    
    public boolean overlaps(DateInterval other) {
        return !(this.to.compareTo(other.from) <= 0 || this.from.compareTo(other.to) >= 0);
    }
}
