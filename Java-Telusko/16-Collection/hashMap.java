import java.util.HashMap;
import java.util.Map;

public class hashMap {

  public static void main(String[] args) {
    Map<String, Integer> marks = new HashMap<String, Integer>();
    marks.put("Ankit", 95);
    marks.put("Sachin", 87);
    marks.put("Akash", 92);
    marks.put("Aditya", 97);

    System.out.println(marks);

    System.out.println(marks.keySet());

    for (String key : marks.keySet()) {
      System.out.println(key + " : " + marks.get(key));
    }
  }
}
