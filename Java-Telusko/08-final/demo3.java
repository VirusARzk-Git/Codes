class A {

  void show1() {
    System.out.println("in A");
  }
}

class B extends A {

  void show2() {
    System.out.println("in B");
  }
}

public class demo3 {

  public static void main(String[] args) {
    A a = new B();
    a.show1();
    // a.show2(); // error: cannot find symbol

    B b = (B) a;
    b.show2();
  }
}
