package CompositePattern.Arithmetic;

public class Number implements ArithmeticExpression {
    private double value;

    public Number(double value) {
        this.value = value;
    }

    @Override
    public double evaluate() {
        return value;
    }
}
