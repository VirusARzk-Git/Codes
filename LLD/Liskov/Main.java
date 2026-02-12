package Liskov;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Vehicle> vehicles = new ArrayList<>();
        vehicles.add(new Motorcycle());
        vehicles.add(new Car());
        vehicles.add(new Bicycle());
        for (Vehicle vehicle : vehicles) {
            System.out.println("Number of wheels: " + vehicle.getNumberOfWheels());
            System.out.println("Has engine: " + vehicle.hasEngine());
            System.out.println();
        }
    }
}
