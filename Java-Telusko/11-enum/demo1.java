enum Status {
  Running,
  Failed,
  Pending,
  Success,
}

public class demo1 {

  public static void main(String[] args) {
    /*
    Status[] s = Status.values();

    // System.out.println(s);

    System.out.println("Status are: ");
    for (Status status : s) System.out.println(
      status + " at index " + status.ordinal()
    );
     */

    Status s = Status.Pending;

    System.out.println(s.getClass().getSuperclass());

    switch (s) {
      case Running:
        System.out.println("All Good");
        break;
      case Failed:
        System.out.println("Try Again");
        break;
      case Pending:
        System.out.println("Please Wait");
        break;
      case Success:
        System.out.println("Done");
        break;
      default:
        System.out.println("Unknown");
    }
  }
}
