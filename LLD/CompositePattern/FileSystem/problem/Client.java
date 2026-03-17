package CompositePattern.FileSystem.problem;

public class Client {
    public static void main(String[] args) {
        Directory root = new Directory("root");
        File file1 = new File("file1.txt");
        File file2 = new File("file2.txt");
        root.add(file1);
        root.add(file2);

        Directory subDir = new Directory("subDir");
        File file3 = new File("file3.txt");
        subDir.add(file3);
        root.add(subDir);

        root.ls();
    }
}
