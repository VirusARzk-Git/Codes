class AnotherException extends Exception {

  AnotherException(String message) {
    super(message);
  }
}

public class demo1 {

  public static void main(String[] args) {
    int i = 3;
    int j = 0;
    int arr[] = new int[3];
    String str = null;

    try {
      if (j == 0) {
        throw new AnotherException("New Exception");
      }
      System.out.println(i / j);
      System.out.println(str.length());
      arr[3] = 10;
    } catch (ArithmeticException e) {
      System.out.println("Error: " + e.getMessage());
    } catch (ArrayIndexOutOfBoundsException e) {
      System.out.println("Error: " + e.getMessage());
    } catch (NullPointerException e) {
      System.out.println("Error: " + e.getMessage());
    } catch (Exception e) {
      System.out.println("Error: " + e.getMessage());
    } finally {
      System.out.println("Finally block");
    }
  }
}
