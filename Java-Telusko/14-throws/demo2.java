import java.util.Scanner;

public class demo2 {
    public static void main(String[] args) {
        System.out.println("Enter the number");

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println("The number is: " + n);

        sc.close();
    }
}
