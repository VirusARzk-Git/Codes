public class arrays {

  public static void main(String[] args) {
    int[] arr = new int[5];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    for (int i = 0; i < arr.length; i++) {
      System.out.println(arr[i]);
    }

    int v[][] = new int[3][4];
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
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
