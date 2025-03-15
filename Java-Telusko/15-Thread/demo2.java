class Counter {

  private int count = 0;

  public synchronized void increment() {
    count++;
  }

  public void decrement() {
    count--;
  }

  public int value() {
    return count;
  }
}

public class demo2 {

  public static void main(String[] args) {
    Counter c = new Counter();

    Runnable a = () -> {
      for (int i = 1; i <= 1500; i++) {
        c.increment();
      }
    };
    Runnable b = () -> {
      for (int i = 1; i <= 1500; i++) {
        c.increment();
      }
    };

    System.out.println("Initial value: " + c.value());
    Thread t1 = new Thread(a);
    Thread t2 = new Thread(b);

    t1.start();
    t2.start();

    try {
      t1.join();
      t2.join();
    } catch (InterruptedException e) {
      e.printStackTrace();
    }

    System.out.println("Final value: " + c.value());
  }
}
