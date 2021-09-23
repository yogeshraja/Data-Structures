import java.util.*;

public class IncreasingDecreasing {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        sc.close();
        HashMap<Character, Integer> mp = new HashMap<>();
        for(char i:str.toCharArray())
        {
            if (!mp.containsKey(i)) {
                mp.put(i, 0);
            }
            mp.put(i, mp.get(i) + 1);
        }
        boolean flag = true;
        boolean flag1=false;
        String result = "";
        while(flag)
        {
            String temp = "";
            flag = false;
            for (char i : mp.keySet()) {
                if (mp.get(i) == 0)
                    continue;
                flag = true;
                temp += i;
                mp.put(i, mp.get(i) - 1);
            }
            result += flag1 ? new StringBuilder().append(temp).reverse() : temp;
        }
        System.out.println(result);
    }
}
