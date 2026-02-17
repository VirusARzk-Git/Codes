package ZoomCar;

public class User {

  int userID;
  String userName;
  String drivingLicenseNumber;

  public User(int userID, String userName, String drivingLicenseNumber) {
    this.userID = userID;
    this.userName = userName;
    this.drivingLicenseNumber = drivingLicenseNumber;
  }

  public int getUserID() {
    return userID;
  }

  public void setUserID(int userID) {
    this.userID = userID;
  }

  public String getUserName() {
    return userName;
  }

  public void setUserName(String userName) {
    this.userName = userName;
  }

  public String getDrivingLicenseNumber() {
    return drivingLicenseNumber;
  }

  public void setDrivingLicenseNumber(String drivingLicenseNumber) {
    this.drivingLicenseNumber = drivingLicenseNumber;
  }
}
