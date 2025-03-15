class Student {

  int rollNo;
  String name;
  int marks;

  Student(int rollNo, String name, int marks) {
    this.rollNo = rollNo;
    this.name = name;
    this.marks = marks;
  }
}

public class objects {

  public static void main(String[] args) {
    Student s1 = new Student(1, "Alice", 90);
    Student s2 = new Student(2, "Bob", 80);
    Student s3 = new Student(3, "Charlie", 70);
    Student s4 = new Student(4, "David", 60);
    Student s5 = new Student(5, "Eve", 50);

    Student[] students = new Student[5];
    students[0] = s1;
    students[1] = s2;
    students[2] = s3;
    students[3] = s4;
    students[4] = s5;

    for (Student s : students) {
      System.out.println(s);
    }
  }
}
