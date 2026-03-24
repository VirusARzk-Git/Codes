package Splitwise;

import Splitwise.Expense.Split.Split;
import Splitwise.User.User;
import java.util.List;
import java.util.Map;

public class BalanceSheetController {

  public void updateUserExpenseBalanceSheet(User paidBy, List<Split> splits, double amount) {
    UserExpenseBalanceSheet paidByUserExpenseBalanceSheet = paidBy.getUserExpenseBalanceSheet();
    paidByUserExpenseBalanceSheet.setTotalExpense(paidByUserExpenseBalanceSheet.getTotalExpense() + amount);
    paidByUserExpenseBalanceSheet.setTotalPayment(paidByUserExpenseBalanceSheet.getTotalPayment() + amount);

    for (Split split : splits) {
      User userOwe = split.getUser();
      double amountOwe = split.getAmountOwed();
      UserExpenseBalanceSheet userOweExpenseBalanceSheet = userOwe.getUserExpenseBalanceSheet();

      if (userOwe.getUserId() != paidBy.getUserId()) {
        paidByUserExpenseBalanceSheet.setTotalExpense(paidByUserExpenseBalanceSheet.getTotalExpense() - amountOwe);

        userOweExpenseBalanceSheet.setTotalExpense(
          userOweExpenseBalanceSheet.getTotalExpense() + amountOwe
        );

        Balance userOweBalance;
        if (paidByUserExpenseBalanceSheet.getUserBalanceSheet().containsKey(userOwe.getUserId())) {
          userOweBalance = paidByUserExpenseBalanceSheet.getUserBalanceSheet().get(userOwe.getUserId());
        } else {
          userOweBalance = new Balance();
          paidByUserExpenseBalanceSheet.getUserBalanceSheet().put(userOwe.getUserId(), userOweBalance);
        }

        Balance paidByBalance;
        if (userOweExpenseBalanceSheet.getUserBalanceSheet().containsKey(paidBy.getUserId())) {
          paidByBalance = userOweExpenseBalanceSheet.getUserBalanceSheet().get(paidBy.getUserId());
        } else {
          paidByBalance = new Balance();
          userOweExpenseBalanceSheet.getUserBalanceSheet().put(paidBy.getUserId(), paidByBalance);
        }

        double userOweAmount = userOweBalance.getAmountOwe();
        double userToReceiveAmount = userOweBalance.getAmountToReceive();

        userOweExpenseBalanceSheet.setTotalReceive(userOweExpenseBalanceSheet.getTotalReceive() - userToReceiveAmount);
        userOweExpenseBalanceSheet.setTotalOwe(userOweExpenseBalanceSheet.getTotalOwe() - userOweAmount);

        paidByUserExpenseBalanceSheet.setTotalReceive(paidByUserExpenseBalanceSheet.getTotalReceive() - userOweAmount);
        paidByUserExpenseBalanceSheet.setTotalOwe(paidByUserExpenseBalanceSheet.getTotalOwe() - userToReceiveAmount);

        if (userToReceiveAmount == 0) {
          userOweBalance.setAmountOwe(userOweAmount + amountOwe);
        } else {
          userOweBalance.setAmountOwe(Math.max(0, amountOwe - userToReceiveAmount));
          userOweBalance.setAmountToReceive(Math.max(0, userToReceiveAmount - amountOwe));
        }
        paidByBalance.setAmountToReceive(userOweBalance.getAmountOwe());
        paidByBalance.setAmountOwe(userOweBalance.getAmountToReceive());

        userOweExpenseBalanceSheet.setTotalReceive(userOweExpenseBalanceSheet.getTotalReceive() + userOweBalance.getAmountToReceive());
        userOweExpenseBalanceSheet.setTotalOwe(userOweExpenseBalanceSheet.getTotalOwe() + userOweBalance.getAmountOwe());

        paidByUserExpenseBalanceSheet.setTotalReceive(paidByUserExpenseBalanceSheet.getTotalReceive() + paidByBalance.getAmountToReceive());
        paidByUserExpenseBalanceSheet.setTotalOwe(paidByUserExpenseBalanceSheet.getTotalOwe() + paidByBalance.getAmountOwe());
      }
    }
  }

  public void showBalanceSheet(User user) {
    System.out.println("-------------------------------");
    System.out.println("Balance Sheet for User: " + user.getName());

    UserExpenseBalanceSheet userExpenseBalanceSheet = user.getUserExpenseBalanceSheet();
    System.out.println("Total Expense: " + userExpenseBalanceSheet.getTotalExpense());
    System.out.println("Total Owe: " + userExpenseBalanceSheet.getTotalOwe());
    System.out.println("Total To Receive: " + userExpenseBalanceSheet.getTotalReceive());
    System.out.println("Total Paid: " + userExpenseBalanceSheet.getTotalPayment());

    for (Map.Entry<Integer, Balance> entry : userExpenseBalanceSheet
      .getUserBalanceSheet()
      .entrySet()) {
      int userId = entry.getKey();
      Balance balance = entry.getValue();

      if (balance.getAmountOwe() > 0) {
        System.out.println("To Receive from User ID: " + userId + ", Amount: " + balance.getAmountOwe());
      }
      
      if (balance.getAmountToReceive() > 0) {
        System.out.println("Owe to User ID: " + userId + ", Amount: " + balance.getAmountToReceive());
      }
    }

    System.out.println("-------------------------------");
  }
}
