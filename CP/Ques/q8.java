import java.util.Scanner;

public class q8 {

  static int result(int n) {
    if (n < 2) return 1;
    return n * (n - 1) * result(n - 2);
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a;
    a = sc.nextInt();
    System.out.println(result(a));
    sc.close();
  }
}
