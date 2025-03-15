public class stringbuffer {
    public static void main(String[] args) {
        StringBuffer name = new StringBuffer("Aditya");
        name.append(" Raj");
        System.out.println("Hello " + name);

        String fullName = name.toString();
        System.out.println("Hello " + fullName);

        name.insert(6, " Kumar");
        System.out.println("Hello " + name);
    }
}
