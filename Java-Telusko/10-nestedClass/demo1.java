class A {

  int age;

  void show() {
    System.out.println("Outer class");
  }

  class B {

    void display() {
      System.out.println("Inner class");
    }
  }
}

public class demo1 {
    public static void main(String[] args) {
        A obj = new A();
        obj.show();
        A.B obj1 = obj.new B();
        obj1.display();
    }
}
