import java.util.*;

public class BTape {
     
     public static int hai(int left, int right, int[] arr) {
         if (left == right)
             return arr[left];
         return hai(left, right - left / 2, arr);
 
     }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int arr[] = { 23, 4, 56, 3, 2, 11, 5, 10 };
        System.out.println(hai(0, arr.length - 1, arr));
        sc.close();
    }
}