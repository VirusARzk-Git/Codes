package Liskov;

public class Bicycle extends Vehicle {

  @Override
  public Boolean hasEngine() {
    return false;
  }
}
