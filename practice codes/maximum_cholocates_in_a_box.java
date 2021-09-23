import java.util.*;

public class maximum_cholocates_in_a_box {
    static int findMaxVal(int[] arr, int m,int sum) {
        int i = 0, j = arr.length - 1;
        while (i < j) {
            if (sum % m == 0) {
                return sum / m; 
            }
            if (arr[i] < arr[j]) {
                sum -= arr[i];
                i++;
            }
            else {
                sum -= arr[j];
                j--;
            }
        }
        return 0;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt(), m = sc.nextInt(),sum=0;
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
                sum += arr[i];
            }
            System.out.println(findMaxVal(arr, m, sum));
        }
        sc.close();
    }
}
