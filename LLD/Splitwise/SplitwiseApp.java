package Splitwise;

import Splitwise.User.User;
import Splitwise.User.UserController;
import Splitwise.Group.Group;
import Splitwise.Group.GroupController;
import Splitwise.Expense.Expense;
import Splitwise.Expense.ExpenseSplitType;
import Splitwise.Expense.Split.Split;
import java.util.*;

public class SplitwiseApp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        UserController userController = new UserController();
        GroupController groupController = new GroupController();
        BalanceSheetController balanceSheetController = new BalanceSheetController();
        int userIdCounter = 1;
        int groupIdCounter = 1;
        int expenseIdCounter = 1;

        while (true) {
            System.out.println("\n--- Splitwise Menu ---");
            System.out.println("1. Add User");
            System.out.println("2. Create Group");
            System.out.println("3. Add User to Group");
            System.out.println("4. Create Expense");
            System.out.println("5. Show User Balance Sheet");
            System.out.println("6. Display All Groups");
            System.out.println("7. Display All Members of a Group");
            System.out.println("8. Exit");
            System.out.print("Enter choice: ");
            int choice = sc.nextInt();
            sc.nextLine();

            if (choice == 1) {
                userIdCounter = addUser(sc, userController, userIdCounter);
            } else if (choice == 2) {
                groupIdCounter = createGroup(sc, userController, groupController, groupIdCounter);
            } else if (choice == 3) {
                addUserToGroup(sc, userController, groupController);
            } else if (choice == 4) {
                expenseIdCounter = createExpense(sc, userController, groupController, expenseIdCounter);
            } else if (choice == 5) {
                showUserBalanceSheet(sc, userController, balanceSheetController);
            } else if (choice == 6) {
                displayAllGroups(groupController);
            } else if (choice == 7) {
                displayAllMembersOfGroup(sc, groupController);
            } else if (choice == 8) {
                System.out.println("Exiting...");
                sc.close();
                return;
            } else {
                System.out.println("Invalid choice!");
            }
        }
    }

    // Function for menu option 1
    private static int addUser(Scanner sc, UserController userController, int userIdCounter) {
        System.out.print("Enter user name: ");
        String name = sc.nextLine();
        User user = new User(userIdCounter, name);
        userController.addUser(user);
        System.out.println("User added with ID: " + user.getUserId());
        return userIdCounter + 1;
    }

    // Function for menu option 2
    private static int createGroup(Scanner sc, UserController userController, GroupController groupController, int groupIdCounter) {
        System.out.print("Enter group name: ");
        String groupName = sc.nextLine();
        System.out.print("Enter creator user ID: ");
        int creatorId = sc.nextInt();
        User creator = userController.getUser(creatorId);
        if (creator == null) {
            System.out.println("User not found!");
            return groupIdCounter;
        }
        groupController.createGroup(groupIdCounter, groupName, creator);
        System.out.println("Group created by " + creator.getName());
        return groupIdCounter + 1;
    }

    // Function for menu option 3
    private static void addUserToGroup(Scanner sc, UserController userController, GroupController groupController) {
        System.out.print("Enter group ID: ");
        int groupId = sc.nextInt();
        System.out.print("Enter user ID to add: ");
        int addUserId = sc.nextInt();
        Group group = groupController.getGroupById(groupId);
        User addUser = userController.getUser(addUserId);
        if (group == null || addUser == null) {
            System.out.println("Group or User not found!");
            return;
        }
        // Check if user is already a member of the group
        for (User member : group.getGroupMembers()) {
            if (member.getUserId() == addUserId) {
                System.out.println("User is already a member of this group.");
                return;
            }
        }
        group.addMember(addUser);
        System.out.println(addUser.getName() + " added to group " + group.getGroupName());
    }

    // Function for menu option 4
    private static int createExpense(Scanner sc, UserController userController, GroupController groupController, int expenseIdCounter) {
        System.out.print("Enter group ID: ");
        int expGroupId = sc.nextInt();
        Group expGroup = groupController.getGroupById(expGroupId);
        if (expGroup == null) {
            System.out.println("Group not found!");
            return expenseIdCounter;
        }
        System.out.print("Enter description: ");
        sc.nextLine();
        String desc = sc.nextLine();
        System.out.print("Enter amount: ");
        double amount = sc.nextDouble();
        System.out.print("Enter paid by user ID: ");
        int paidById = sc.nextInt();
        User paidBy = userController.getUser(paidById);
        if (paidBy == null) {
            System.out.println("User not found!");
            return expenseIdCounter;
        }
        // Check if paidBy is a member of the group
        boolean isMember = false;
        for (User member : expGroup.getGroupMembers()) {
            if (member.getUserId() == paidById) {
                isMember = true;
                break;
            }
        }
        if (!isMember) {
            System.out.println("Error: User is not a member of this group. Cannot add expense.");
            return expenseIdCounter;
        }

        System.out.print("Enter split type (EQUAL/EXACT/PERCENTAGE): ");
            String splitTypeStr = sc.next();
            ExpenseSplitType splitType;
            try {
                splitType = ExpenseSplitType.valueOf(splitTypeStr.toUpperCase());
            } catch (IllegalArgumentException e) {
                System.out.println("Invalid split type! Please enter EQUAL, EXACT, or PERCENTAGE.");
                return expenseIdCounter;
            }
            List<Split> splits = new ArrayList<>();
            switch (splitType) {
            case EQUAL: {
                int numMembers = expGroup.getGroupMembers().size();
                double equalAmt = amount / numMembers;
                for (User member : expGroup.getGroupMembers()) {
                    splits.add(new Split(member, equalAmt));
                }
                break;
            }
            case EXACT: {
                double sum = 0;
                for (User member : expGroup.getGroupMembers()) {
                    System.out.print("Enter exact amount for " + member.getName() + ": ");
                    double exactAmt = sc.nextDouble();
                    splits.add(new Split(member, exactAmt));
                    sum += exactAmt;
                }
                break;
            }
            case PERCENTAGE: {
                double percentSum = 0;
                List<Double> percents = new ArrayList<>();
                for (User member : expGroup.getGroupMembers()) {
                    System.out.print("Enter percentage for " + member.getName() + ": ");
                    double percent = sc.nextDouble();
                    percents.add(percent);
                }

                int idx = 0;
                for (User member : expGroup.getGroupMembers()) {
                    double percentAmt = (percents.get(idx) / 100.0) * amount;
                    splits.add(new Split(member, percentAmt));
                    idx++;
                }
                break;
            }
            default:
                System.out.println("Invalid split type!");
                return expenseIdCounter;
        }
        Expense expense = expGroup.createExpense(expenseIdCounter, desc, amount, splits, paidBy, splitType);
        System.out.println("Expense added by " + paidBy.getName() + ".");
        return expenseIdCounter + 1;
    }

    // Function for menu option 5
    private static void showUserBalanceSheet(Scanner sc, UserController userController, BalanceSheetController balanceSheetController) {
        System.out.print("Enter user ID: ");
        int balUserId = sc.nextInt();
        User balUser = userController.getUser(balUserId);
        if (balUser == null) {
            System.out.println("User not found!");
            return;
        }
        balanceSheetController.showBalanceSheet(balUser);
    }

    // Function for menu option 6
    private static void displayAllGroups(GroupController groupController) {
        List<Group> allGroups = groupController.getGroupList();
        if (allGroups.isEmpty()) {
            System.out.println("No groups found.");
        } else {
            System.out.println("All Groups:");
            for (Group g : allGroups) {
                System.out.println("Group ID: " + g.getGroupId() + ", Name: " + g.getGroupName());
            }
        }
    }

    // Function for menu option 7
    private static void displayAllMembersOfGroup(Scanner sc, GroupController groupController) {
        System.out.print("Enter group ID: ");
        int groupId = sc.nextInt();
        Group group = groupController.getGroupById(groupId);
        if (group == null) {
            System.out.println("Group not found!");
            return;
        }
        List<User> members = group.getGroupMembers();
        if (members.isEmpty()) {
            System.out.println("No members in this group.");
        } else {
            System.out.println("Members of Group '" + group.getGroupName() + "':");
            for (User m : members) {
                System.out.println("User ID: " + m.getUserId() + ", Name: " + m.getName());
            }
        }
    }
}