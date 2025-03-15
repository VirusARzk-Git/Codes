interface A {
  void show();
  void display();
}

interface B {
  void config();
}

class C implements A, B {

  public void show() {
    System.out.println("Show");
  }

  public void display() {
    System.out.println("Display");
  }

  public void config() {
    System.out.println("Config");
  }
}

public class demo4 {

  public static void main(String[] args) {
    C obj = new C();
    obj.show();
    obj.display();
    obj.config();
  }
}
