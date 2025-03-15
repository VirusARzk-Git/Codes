import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class demo3 {

  public static void main(String[] args)
    throws NumberFormatException, IOException {
    int num = 0;
    try (
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in))
    ) {
      System.out.println("Enter the number");
      num = Integer.parseInt(br.readLine());
    } catch (IOException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    } finally {
      System.out.println("The number is: " + num);
    }
  }
}
