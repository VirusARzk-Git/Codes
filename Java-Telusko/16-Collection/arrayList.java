import java.util.ArrayList;
// import java.util.Collection;
// import java.util.List;

public class arrayList {

  public static void main(String[] args) {
    // Collection<Integer> nums = new ArrayList<Integer>();
    ArrayList<Integer> nums = new ArrayList<Integer>();
    nums.add(1);
    nums.add(2);
    // nums.add(3);
    nums.add(4);
    nums.add(5);
    nums.add(3);
    // nums.add("6");

    // System.out.println(nums);
    // System.out.println(nums.size());
    // System.out.println(nums.contains(3));
    // nums.remove(3);

    System.out.println(nums);

    // for (Integer n : nums) {
    //   System.out.println(n * 2);
    // }

    System.out.println(nums.indexOf(3));
    System.out.println(nums.get(3));
  }
}
