@FunctionalInterface
interface A {
  int add(int i, int j);
}

public class demo1 {

  public static void main(String[] args) {
    // 1. Using Lambda Expression
    A obj1 = new A() {
      public int add(int i, int j) {
        return i + j;
      }
    };

    // 2. Using Lambda Expression
    A obj2 = (i, j) -> i + j;

    System.out.println(obj1.add(10, 20));
    System.out.println(obj2.add(100, 200));
  }
}
