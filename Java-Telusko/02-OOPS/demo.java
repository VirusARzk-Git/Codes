class Calculator {

  int add(int num1, int num2) {
    return num1 + num2;
  }

  int add(int num1, int num2, int num3) {
    return num1 + num2 + num3;
  }

  double add(double a, double b) {
    return a + b;
  }
}

public class demo {

  public static void main(String[] args) {
    int num1 = 10, num2 = 20;
    Calculator calc = new Calculator(); // Creating object of Calculator class
    int result = calc.add(num1, num2); // Calling add method of Calculator class
    System.out.println(
      "Addition of " + num1 + " and " + num2 + " is: " + result
    );
    double a = 1.1, b = 2.2;
    double result1 = calc.add(a, b);
    System.out.println("Addition of " + a + " and " + b + " is: " + result1);
  }
}
