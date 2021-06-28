import java.util.Scanner;

public class oddsandevens {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int start = sc.nextInt(), end = sc.nextInt(),i=0;
        while (i<=(end-start))
        {
            if ((start + i) % 2 == 1) {
                System.out.print((start + i) + " ");
            }
            if ((end - i) % 2 == 0) {
                System.out.print((end - i) + " ");
            }
            i++;
        }
        sc.close();
    }
}
