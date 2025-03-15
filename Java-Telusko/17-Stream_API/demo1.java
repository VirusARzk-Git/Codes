import java.util.Arrays;
import java.util.List;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Stream;

public class demo1 {

  public static void main(String[] args) {
    List<Integer> nums = Arrays.asList(5, 6, 3, 4, 7, 1, 2);

    Function<Integer, Integer> f1 = new Function<Integer, Integer>() {
      @Override
      public Integer apply(Integer n) {
        return n * n;
      }
    };

    System.out.println(nums);

    Consumer<Integer> method1 = new Consumer<Integer>() {
      @Override
      public void accept(Integer t) {
        System.out.print(t + " ");
      }
    };

    Consumer<Integer> method2 = n -> System.out.print(n + " ");

    nums.forEach(method1);

    System.out.println();

    nums.forEach(method2);

    System.out.println();

    nums.forEach(n -> System.out.print(n + " "));

    System.out.println();

    Stream<Integer> s1 = nums.stream();
    Stream<Integer> s2 = s1.filter(n -> n % 2 == 1);
    Stream<Integer> s3 = s2.map(n -> n * n);
    // s3.forEach(n -> System.out.print(n + " "));

    int sum1 = s3.reduce(0, (n1, n2) -> n1 + n2);
    System.out.println(sum1);

    Predicate<Integer> p = new Predicate<Integer>() {
      public boolean test(Integer n) {
        return n % 2 == 1;
      }
    };

    int sum2 = nums.stream().filter(p).map(f1).reduce(0, (n1, n2) -> n1 + n2);
    System.out.println(sum2);
    // every stream can be used only once

    Stream<Integer> sortedOddValues = nums.stream().filter(p).sorted();

    sortedOddValues.forEach(method1);
    System.out.println();
  }
}
