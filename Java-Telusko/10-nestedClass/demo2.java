class A {
    public void show() {
        System.out.println("in Show");
    }
}

public class demo2 {
    public static void main(String[] args) {
        A obj = new A() {
            public void show() {
                System.out.println("in Anonymous class");
            }
        };
        obj.show();
    }
}
