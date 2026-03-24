package Splitwise.User;

import Splitwise.UserExpenseBalanceSheet;

public class User {

  final int userId;
  final String name;
  UserExpenseBalanceSheet userExpenseBalanceSheet;

  public User(int userId, String name) {
    this.userId = userId;
    this.name = name;
    userExpenseBalanceSheet = new UserExpenseBalanceSheet();
  }

  public int getUserId() {
    return userId;
  }

  public String getName() {
    return name;
  }

  public UserExpenseBalanceSheet getUserExpenseBalanceSheet() {
    return userExpenseBalanceSheet;
  }
}
