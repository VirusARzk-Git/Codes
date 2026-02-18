package ProxyDesignPattern;

public interface EmployeeDao {
    public void create(ClientType clientType, EmployeeDo obj);
    public void delete(ClientType clientType, int empID);
    public EmployeeDo get(ClientType clientType, int empID);
}
