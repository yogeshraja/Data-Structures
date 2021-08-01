import java.util.*;

class difference {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int out = 0;
        int maxDiff=0;
        for (int i = 0; i < n; i++) {
            int n1 = 0, n2 = 0;
            for (int j = 0; j < n; j++) {
                if (j < i && arr[j] > arr[i]) {
                    n1++;
                } else if (j > i && arr[j] < arr[i]) {
                    n2++;
                }
            }
            if (Math.abs(n1 - n2) > maxDiff) {
                maxDiff = Math.abs(n1 - n2);
                out = i;
            }

        }
        System.out.println(out);
        sc.close();
    }
}
