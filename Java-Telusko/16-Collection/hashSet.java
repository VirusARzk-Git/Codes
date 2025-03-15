import java.util.HashSet;
import java.util.Set;

public class hashSet {

  public static void main(String[] args) {
    Set<Integer> nums = new HashSet<Integer>();
    nums.add(31);
    nums.add(12);
    nums.add(93);
    nums.add(54);
    System.out.println(nums);

    for (Integer o : nums) {
      System.out.println(o);
    }
  }
}
