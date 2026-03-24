package Splitwise.Expense.Split;

import java.util.List;

public class PercentageSplit implements ExpenseSplit {

  @Override
  public void validateSplitRequest(List<Split> splits, double totalAmount) {
    double sum = 0;
    for (Split split : splits) {
      sum += split.getAmountOwed();
    }
    // Allow a small epsilon for floating point errors
    if (Math.abs(sum - totalAmount) > 0.01) {
      throw new IllegalArgumentException(
        "Total split amounts do not sum up to total expense amount"
      );
    }
  }
}
