abstract class Car {

  public abstract void drive();

  public abstract void fly();

  public void playMusic() {
    System.out.println("Playing music");
  }
}

abstract class WagonR extends Car {

  public void drive() {
    System.out.println("Driving WagonR");
  }

  public void fly() {
    System.out.println("Flying WagonR");
  }
}

class UpdatedWagonR extends WagonR {

  public void fly() {
    System.out.println("Flying UpdatedWagonR");
  }
}

public class demo {

  public static void main(String[] args) {
    UpdatedWagonR c = new UpdatedWagonR();
    c.drive();
    c.playMusic();
    c.fly();
  }
}
