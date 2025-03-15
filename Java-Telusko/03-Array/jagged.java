public class jagged {

  public static void main(String[] args) {
    int v[][] = new int[3][];
    v[0] = new int[3];
    v[1] = new int[2];
    v[2] = new int[4];

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < v[i].length; j++) {
        v[i][j] = (int) (Math.random() * 100) + 1;
      }
    }

    for (int a[] : v) {
      for (int b : a) {
        System.out.print(b + " ");
      }
      System.out.println();
    }
  }
}
