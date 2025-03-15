interface Computer {
  public abstract void code();
}

class Laptop implements Computer {

  public void code() {
    System.out.println("Coding in Laptop");
  }
}

class Desktop implements Computer {

  public void code() {
    System.out.println("Coding in Desktop");
  }
}

class Developer {

  public void develop(Computer c) {
    c.code();
  }
}

class demo3 {

  public static void main(String[] args) {
    Developer d = new Developer();
    d.develop(new Laptop());
    d.develop(new Desktop());
  }
}
