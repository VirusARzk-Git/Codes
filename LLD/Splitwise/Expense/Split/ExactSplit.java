package Splitwise.Expense.Split;

import java.util.List;

public class ExactSplit implements ExpenseSplit {

    @Override
    public void validateSplitRequest(List<Split> splits, double totalAmount) {
        double totalSplitAmount = 0;
        for (Split split : splits) {
            totalSplitAmount += split.getAmountOwed();
        }
        if (totalSplitAmount != totalAmount) {
            throw new IllegalArgumentException("Total split amount does not match total expense amount");
        }
    }

}
