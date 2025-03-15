import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

class Student implements Comparable<Student> {

  int age;
  String name;

  Student(int age, String name) {
    this.age = age;
    this.name = name;
  }

  public String toString() {
    return "Student{" + "age=" + age + ", name='" + name + '\'' + '}';
  }

  @Override
  public int compareTo(Student that) {
    return this.name.compareTo(that.name);
    // return this.age - that.age;
  }
}

public class sort2 {

  public static void main(String[] args) {
    Comparator<Student> com = (i, j) -> i.age - j.age;

    List<Student> students = new ArrayList<>();
    students.add(new Student(22, "Charlie"));
    students.add(new Student(19, "David"));
    students.add(new Student(20, "Bob"));
    students.add(new Student(21, "Alice"));
    students.add(new Student(23, "Eve"));

    System.out.println("Before sorting: ");
    for (Student stu : students) {
      System.out.println(stu);
    }

    students.sort(null);

    System.out.println("\nAfter sorting by name: ");
    for (Student stu : students) {
      System.out.println(stu);
    }

    students.sort(com);

    System.out.println("\nAfter sorting by age: ");
    for (Student stu : students) {
      System.out.println(stu);
    }
  }
}
