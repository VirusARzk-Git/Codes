package Liskov;

public class Car extends Vehicle {
    @Override
    public Integer getNumberOfWheels() {
        return 4;
    }
}
