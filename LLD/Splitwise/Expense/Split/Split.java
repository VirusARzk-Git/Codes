package Splitwise.Expense.Split;

import Splitwise.User.User;

public class Split {
    final User user;  
    final double amountOwed;

    public Split(User user, double amountOwed) {
        this.user = user;
        this.amountOwed = amountOwed;
    }

    public User getUser() {
        return user;
    }

    public double getAmountOwed() {
        return amountOwed;
    }
}
