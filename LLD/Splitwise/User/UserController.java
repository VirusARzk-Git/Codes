package Splitwise.User;

import java.util.ArrayList;
import java.util.List;

public class UserController {

  List<User> userList;

  public UserController() {
    this.userList = new ArrayList<>();
  }

  // add user
  public void addUser(User user) {
    userList.add(user);
  }

  // get user by id
  public User getUser(int userId) {
    for (User user : userList) {
      if (user.getUserId() == userId) {
        return user;
      }
    }
    return null;
  }

  // get all users
  public List<User> getAllUsers() {
    return userList;
  }
}
