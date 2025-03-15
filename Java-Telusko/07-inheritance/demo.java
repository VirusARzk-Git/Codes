class A {

  public A() {
    System.out.println("in A");
  }

  public A(int x) {
    System.out.println("in A int");
  }
}

class B extends A {

  public B() {
    System.out.println("in B");
  }

  public B(int x) {
    this();
    System.out.println("in B int");
  }
}

public class demo {

  public static void main(String[] args) {
    B obj1 = new B(5);
    B obj2 = new B();
  }
}
