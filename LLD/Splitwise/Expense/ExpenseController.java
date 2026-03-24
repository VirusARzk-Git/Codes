package Splitwise.Expense;

import java.util.List;

import Splitwise.BalanceSheetController;
import Splitwise.Expense.Split.ExpenseSplit;
import Splitwise.Expense.Split.Split;
import Splitwise.User.User;

public class ExpenseController {
    BalanceSheetController balanceSheetController;

    public ExpenseController() {
        this.balanceSheetController = new BalanceSheetController();
    }

    public Expense createExpense(int expenseId, String description, double amount, ExpenseSplitType splitType, List<Split> splits, User paidBy) {
        ExpenseSplit expenseSplit = SplitFactory.getSplitObject(splitType);
        try{
        expenseSplit.validateSplitRequest(splits, amount);
        Expense expense = new Expense(expenseId, description, amount, paidBy, splitType);
        balanceSheetController.updateUserExpenseBalanceSheet(paidBy, splits, amount);
        return expense;
        }
        catch(IllegalArgumentException e) {
            System.out.println("Error creating expense: " + e.getMessage());
            return null;
        }
    }
}
