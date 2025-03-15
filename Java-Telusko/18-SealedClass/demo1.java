sealed class A extends Thread implements Cloneable permits B, C {}

// sealed class can extend a sealed, non-sealed, or final class

non-sealed class B extends A {}

final class C extends A {}

class D extends B {}

sealed interface E permits F {}

non-sealed interface F extends E {}


public class demo1 {

  public static void main(String[] args) {}
}
