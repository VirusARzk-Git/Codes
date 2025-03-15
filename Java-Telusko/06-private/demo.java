class Human {

  private String name;
  private int age;

  Human(String name, int age) {
    this.name = name;
    this.age = age;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public int getAge() {
    return age;
  }

  public void setAge(int age) {
    this.age = age;
  }
}

public class demo {

  public static void main(String[] args) {
    Human human = new Human("John", 30);

    System.out.println("Name: " + human.getName());
    System.out.println("Age: " + human.getAge());
  }
}
