package Splitwise.Group;

import Splitwise.Expense.Expense;
import Splitwise.Expense.ExpenseController;
import Splitwise.Expense.ExpenseSplitType;
import Splitwise.Expense.Split.Split;
import Splitwise.User.User;
import java.util.ArrayList;
import java.util.List;

public class Group {

  final int groupId;
  final String groupName;
  List<User> groupMembers;

  List<Expense> expenseList;
  ExpenseController expenseController;

  Group(int groupId, String groupName) {
    this.groupId = groupId;
    this.groupName = groupName;
    this.groupMembers = new ArrayList<>();
    this.expenseList = new ArrayList<>();
    this.expenseController = new ExpenseController();
  }

  public void addMember(User user) {
    this.groupMembers.add(user);
  }

  public String getGroupName() {
    return groupName;
  }

  public int getGroupId() {
    return groupId;
  }

  public List<User> getGroupMembers() {
    return groupMembers;
  }

  public Expense createExpense(int expenseId, String description, double amount, List<Split>splits, User paidBy, ExpenseSplitType splitType) {
    Expense expense = expenseController.createExpense(expenseId, description, amount, splitType, splits, paidBy);
    expenseList.add(expense);
    return expense;
    
  }
}
