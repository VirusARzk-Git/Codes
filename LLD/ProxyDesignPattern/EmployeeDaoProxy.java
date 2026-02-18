package ProxyDesignPattern;

public class EmployeeDaoProxy implements EmployeeDao {
    private EmployeeDao employeeDaoObj;

    public EmployeeDaoProxy(ClientType clientType) {
        employeeDaoObj = new EmployeeDaoImpl();
    }

    @Override
    public void create(ClientType clientType, EmployeeDo obj) {
        if (clientType == ClientType.ADMIN) {
            employeeDaoObj.create(clientType, obj);
        } else {
            System.out.println("Only ADMIN can create employee records.");
        }
    }
    @Override
    public void delete(ClientType clientType, int empID) {
        if (clientType == ClientType.ADMIN) {
            employeeDaoObj.delete(clientType, empID);
        } else {
            System.out.println("Only ADMIN can delete employee records.");
        }
    }
    @Override
    public EmployeeDo get(ClientType clientType, int empID) {
        if (clientType == ClientType.ADMIN || clientType == ClientType.USER) {
            return employeeDaoObj.get(clientType, empID);
        } else {
            System.out.println("Only ADMIN or USER can get employee records.");
            return null;
        }
    }
}
