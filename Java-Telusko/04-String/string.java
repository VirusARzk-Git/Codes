class string {

  public static void main(String[] args) {
    String name = "Aditya";
    String nick_name = new String("Virus");
    System.out.println("Hello " + name);
    System.out.println("Hello " + nick_name);
    System.out.println(name.concat(" Raj"));

    name = name + " Raj";
    System.out.println(name);
  }
}
