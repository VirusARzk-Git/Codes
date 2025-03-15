import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

public class treeSet {

  public static void main(String[] args) {
    Set<Integer> nums = new TreeSet<Integer>();

    nums.add(31);
    nums.add(12);
    nums.add(93);
    nums.add(54);
    System.out.println(nums);

    Iterator<Integer> values = nums.iterator();
    while (values.hasNext()) {
      System.out.println(values.next());
    }
  }
}
