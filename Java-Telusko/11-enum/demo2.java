enum Laptop {
  Macbook(2000),
  XPS(2200),
  Surface(1500),
  Thinkpad(1800);

  private int price;

  private Laptop() {
    this.price = 1000;
  }

  private Laptop(int price) {
    this.price = price;
  }

  public int getPrice() {
    return price;
  }

  public void setPrice(int price) {
    this.price = price;
  }
}

public class demo2 {

  public static void main(String[] args) {
    // Laptop myLaptop = Laptop.XPS;
    // System.out.println("My laptop is " + myLaptop + " and it costs " + myLaptop.getPrice());

    for (Laptop laptop : Laptop.values()) {
      System.out.println(laptop + " costs " + laptop.getPrice());
    }
  }
}
