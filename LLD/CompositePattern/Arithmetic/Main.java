package CompositePattern.Arithmetic;

public class Main {

  public static void main(String[] args) {
    ArithmeticExpression expression1 = new Expression(
      new Number(5),
      new Number(3),
      OperationType.ADD
    );

    ArithmeticExpression expression2 = new Expression(
      new Number(10),
      new Number(2),
      OperationType.MULTIPLY
    );

    ArithmeticExpression combinedExpression = new Expression(
      expression1,
      expression2,
      OperationType.SUBTRACT
    );

    System.out.println("Result: " + combinedExpression.evaluate());
  }
}
