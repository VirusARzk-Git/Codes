package Splitwise.Expense;

import java.util.ArrayList;
import java.util.List;

import Splitwise.Expense.Split.Split;
import Splitwise.User.User;

public class Expense {
    int expenseId;
    String description;
    double amount;
    User paidBy;
    ExpenseSplitType splitType;
    List<Split> splits;

    public Expense(int expenseId, String description, double amount, User paidBy, ExpenseSplitType splitType) {
        this.expenseId = expenseId;
        this.description = description;
        this.amount = amount;
        this.paidBy = paidBy;
        this.splitType = splitType;
        this.splits = new ArrayList<>();
    }
}
