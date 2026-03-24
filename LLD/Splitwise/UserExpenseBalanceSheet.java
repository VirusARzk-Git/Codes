package Splitwise;

import java.util.HashMap;
import java.util.Map;

public class UserExpenseBalanceSheet {

  Map<Integer, Balance> userBalanceSheet;
  double totalExpense;
  double totalPayment;
  double totalOwe;
  double totalReceive;

  public UserExpenseBalanceSheet() {
    userBalanceSheet = new HashMap<>();
    totalExpense = 0;
    totalPayment = 0;
    totalOwe = 0;
    totalReceive = 0;
  }

  public Map<Integer, Balance> getUserBalanceSheet() {
    return userBalanceSheet;
  }

  public double getTotalExpense() {
    return totalExpense;
  }

  public void setTotalExpense(double totalExpense) {
    this.totalExpense = totalExpense;
  }

  public double getTotalPayment() {
    return totalPayment;
  }

  public void setTotalPayment(double totalPayment) {
    this.totalPayment = totalPayment;
  }

  public double getTotalOwe() {
    return totalOwe;
  }

  public void setTotalOwe(double totalOwe) {
    this.totalOwe = totalOwe;
  }

  public double getTotalReceive() {
    return totalReceive;
  }

  public void setTotalReceive(double totalReceive) {
    this.totalReceive = totalReceive;
  }
}
