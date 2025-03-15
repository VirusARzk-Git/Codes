import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class demo1 {

  public static void main(String[] args) throws IOException {
    System.out.println("Enter the number");

    InputStreamReader in = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(in);

    int n = Integer.parseInt(br.readLine());
    System.out.println("The number is: " + n);

    br.close();
  }
}
