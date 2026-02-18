package ProxyDesignPattern;

public class EmployeeDaoImpl implements EmployeeDao {

  @Override
  public void create(ClientType clientType, EmployeeDo obj) {
    // Create a new employee record in the database
    System.out.println("Created a new employee record");
  }

  @Override
  public void delete(ClientType clientType, int empID) {
    // Delete an employee record from the database
    System.out.println("Deleted employee record with ID: " + empID);
  }

  @Override
  public EmployeeDo get(ClientType clientType, int empID) {
    // fetch employee information from the database
    System.out.println("Fetching data from the DB");
    return new EmployeeDo();
  }
}
