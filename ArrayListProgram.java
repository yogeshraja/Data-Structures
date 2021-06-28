import java.util.*;
import java.util.Iterator;

public class ArrayListProgram {

  public static void main(String[] args) throws Exception {

    // List 1:
    ArrayList<Integer> list1 = new ArrayList<Integer>();
    int[] n1 = {60, 70, 20, 40, 30, 60};
    for (int i = 0; i < n1.length; i++) {
      list1.add(n1[i]);
    }
    System.out.println("List 1 created. ");
    Iterator<Integer> itr1 = list1.iterator();
    while (itr1.hasNext()) {
      System.out.println(itr1.next());
    }

    System.out.println("\nRemoving 60 from list 1.");
    list1.remove(5);
    Iterator<Integer> itr2 = list1.iterator();
    while (itr2.hasNext()) {
      System.out.println(itr2.next());
    }

    // List 2:
    List<Integer> list2 = new ArrayList<Integer>();
    int[] n2 = {100, 500, 200, 100};
    for (int i = 0; i < n2.length; i++) {
      list2.add(n2[i]);
    }
    System.out.println("\nList 2 created. ");

    for (int j = 0; j < list2.size(); j++) {
      System.out.println(list2.get(j));
    }
    list1.addAll(list2);
    System.out.println("\nAfter merging List 1 and List 2.");

    for (int j = 0; j < list1.size(); j++) {
      System.out.println(list1.get(j));
    }
  }
}