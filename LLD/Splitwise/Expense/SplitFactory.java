package Splitwise.Expense;
import Splitwise.Expense.Split.EqualSplit;
import Splitwise.Expense.Split.ExactSplit;
import Splitwise.Expense.Split.ExpenseSplit;
import Splitwise.Expense.Split.PercentageSplit;

public class SplitFactory {
    public static ExpenseSplit getSplitObject(ExpenseSplitType splitType) {
        switch (splitType) {
            case EQUAL:
                return new EqualSplit();
            case EXACT:
                return new ExactSplit();
            case PERCENTAGE:
                return new PercentageSplit();
            default:
                throw new IllegalArgumentException("Invalid split type");
        }
    }
}
