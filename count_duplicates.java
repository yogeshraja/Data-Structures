import java.util.*;

public class count_duplicates {

    public static int countDuplicate(List<Integer> numbers)
    {
        HashSet<Integer> hst = new HashSet<>();
        HashSet<Integer> hst1 = new HashSet<>();
        for (int i : numbers) {
            if (hst.contains(i)) {
                hst1.add(i);
            }
            hst.add(i);
        }
        return hst1.size();
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> ls = new ArrayList<>();
        while(n-->0)
        {
            ls.add(sc.nextInt());
        }
        sc.close();
        System.out.println(countDuplicate(ls));
    }
    
}
