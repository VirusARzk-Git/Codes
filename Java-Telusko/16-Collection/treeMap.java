import java.util.TreeMap;
import java.util.Map;

public class treeMap {

  public static void main(String[] args) {
    Map<String, Integer> marks = new TreeMap<String, Integer>();
    marks.put("Ankit", 95);
    marks.put("Sachin", 87);
    marks.put("Akash", 92);
    marks.put("Aditya", 97);

    System.out.println(marks);
  }
}
