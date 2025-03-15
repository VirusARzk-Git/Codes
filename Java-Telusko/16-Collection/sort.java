import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class sort {

  public static void main(String[] args) {
    Comparator<Integer> com = new Comparator<Integer>() {
      public int compare(Integer i, Integer j) {
        if (i % 10 > j % 10) {
          return 1;
        } else {
          return -1;
        }
      }
    };

    List<Integer> nums = new ArrayList<>();

    nums.add(45);
    nums.add(13);
    nums.add(21);
    nums.add(34);
    nums.add(52);
    System.out.println("Before sorting: " + nums);
    nums.sort(null);
    System.out.println("After sorting: " + nums);
    Collections.sort(nums, com);
    System.out.println("After sorting: " + nums);
  }
}
