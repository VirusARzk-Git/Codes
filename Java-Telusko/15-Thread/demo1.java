class B implements Runnable {

  public void run() {
    for (int i = 0; i < 50; i++) {
      System.out.println("B: " + i);
      try {
        Thread.sleep(100);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }
}

public class demo1 {

  public static void main(String[] args) {
    Runnable a = () -> {
      for (int i = 0; i < 50; i++) {
        System.out.println("A: " + i);
        try {
          Thread.sleep(100);
        } catch (InterruptedException e) {
          e.printStackTrace();
        }
      }
    };
    Runnable b = new B();

    Thread t1 = new Thread(a);
    Thread t2 = new Thread(b);

    t1.start();
    t2.start();
  }
}
