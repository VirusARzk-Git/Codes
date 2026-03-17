package CompositePattern.Arithmetic;

public class Expression implements ArithmeticExpression {

  ArithmeticExpression leftExpression;
  ArithmeticExpression rightExpression;
  OperationType operationType;

  public Expression(
    ArithmeticExpression leftExpression,
    ArithmeticExpression rightExpression,
    OperationType operationType
  ) {
    this.leftExpression = leftExpression;
    this.rightExpression = rightExpression;
    this.operationType = operationType;
  }

  @Override
  public double evaluate() {
    double leftValue = leftExpression.evaluate();
    double rightValue = rightExpression.evaluate();

    switch (operationType) {
      case ADD:
        return leftValue + rightValue;
      case SUBTRACT:
        return leftValue - rightValue;
      case MULTIPLY:
        return leftValue * rightValue;
      case DIVIDE:
        if (rightValue == 0) {
          throw new ArithmeticException("Division by zero");
        }
        return leftValue / rightValue;
      default:
        throw new IllegalArgumentException("Invalid operation type");
    }
  }
}
