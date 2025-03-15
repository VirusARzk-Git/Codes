class Mobile {

  String brand;
  int price;
  static String name;

  static {
    name = "SmartPhone";
    System.out.println("Static block");
  }

  Mobile() {
    brand = "";
    price = 0;
    System.out.println("Constructor");
  }

  void display() {
    System.out.println(brand + " : " + price + " : " + name);
  }

  static void displayStatic(Mobile m) {
    System.out.println(m.brand + " : " + m.price + " : " + name);
  }
}

public class keyword {

  public static void main(String[] args) {
    Mobile m1 = new Mobile();
    m1.brand = "Samsung";
    m1.price = 15000;
    // m1.name = "Mobile";
    Mobile.name = "SmartPhone";
    m1.display();

    Mobile m2 = new Mobile();
    m2.brand = "Apple";
    m2.price = 50000;
    Mobile.displayStatic(m2);
  }
}
