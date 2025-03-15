class Calc {

  public final int add(int a, int b) {  // final prevents overriding
    return a + b;
  }
}

class AdvCalc extends Calc {
  /*
    public int add(int a, int b) {    
    return a + b + 100;
    }
    */
  // error: add(int,int) in AdvCalc cannot override add(int,int) in Calc
}

public class demo2 {

  public static void main(String[] args) {
    Calc c = new Calc();
    System.out.println(c.add(10, 20));
  }
}
