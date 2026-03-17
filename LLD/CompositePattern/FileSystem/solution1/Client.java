package CompositePattern.FileSystem.solution1;

public class Client {

  public static void main(String[] args) {
    Directory root = new Directory("Movies");
    root.add(new File("Border.mkv"));

    Directory subDir = new Directory("Comedy Movies");
    subDir.add(new File("Hera Pheri.mkv"));
    subDir.add(new File("Andaz Apna Apna.mkv"));
    root.add(subDir);

    subDir = new Directory("Anime Movies");
    subDir.add(new File("Your Name.mkv"));
    subDir.add(new File("Spirited Away.mkv"));
    root.add(subDir);

    root.ls();
  }
}
