package CompositePattern.FileSystem.solution1;

import java.util.ArrayList;
import java.util.List;

public class Directory implements FileSystem {

  String directoryName;
  List<FileSystem> objectList;

  public Directory(String name) {
    this.directoryName = name;
    this.objectList = new ArrayList<>();
  }

  public void add(FileSystem fs) {
    objectList.add(fs);
  }

  public void ls() {
    System.out.println("Directory Name: " + directoryName);
    for (FileSystem fs : objectList) {
      fs.ls();
    }
  }
}
