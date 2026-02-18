package ProxyDesignPattern;

public class EmployeeManagement {
    public static void main(String[] args) {
        System.out.println("=======PROXY DESIGN PATTERN========");
        EmployeeDaoProxy employeeDaoProxyAdmin = new EmployeeDaoProxy(ClientType.ADMIN);
        EmployeeDaoProxy employeeDaoProxyUser = new EmployeeDaoProxy(ClientType.USER);
        EmployeeDo emp = new EmployeeDo();
        employeeDaoProxyAdmin.create(ClientType.ADMIN, emp);
        employeeDaoProxyUser.get(ClientType.USER, 1);
        employeeDaoProxyAdmin.delete(ClientType.USER, 3);
    }
}
