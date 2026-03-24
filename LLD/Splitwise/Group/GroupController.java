package Splitwise.Group;

import Splitwise.User.User;
import java.util.ArrayList;
import java.util.List;

public class GroupController {

  List<Group> groupList;

  public GroupController() {
    this.groupList = new ArrayList<>();
  }

  // create a new group
  public void createGroup(int groupId, String groupName, User creator) {
    Group newGroup = new Group(groupId, groupName);
    newGroup.addMember(creator);
    this.groupList.add(newGroup);
  }

  public Group getGroupById(int groupId) {
    for (Group group : groupList) {
      if (group.getGroupId() == groupId) {
        return group;
      }
    }
    return null; // or throw an exception
  }

  public List<Group> getGroupList() {
    return groupList;
  }
}
