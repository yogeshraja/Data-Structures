#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    int mat[n][n];
    memset(mat, 0, n * n * sizeof(int));
    int x = 1;
    int r = 0, c = 0;
    int r1 = -1, r2 = n, c1 = -1, c2 = n;
    while (x <= n * n)
    {
        for (c; c < c2; c++)
            mat[r][c] = x++;
        r1++;
        c--;
        r++;
        if (x >= n * n)
            break;

        for (r; r < r2; r++)
            mat[r][c] = x++;
        c2--;
        r--;
        c--;
        if (x >= n * n)
            break;
        for (c; c > c1; c--)
            mat[r][c] = x++;
        r2--;
        c++;
        r--;
        if (x >= n * n)
            break;
        for (r; r > r1; r--)
            mat[r][c] = x++;
        c1++;
        r++;
        c++;
    }
    for (int i = 0; i < n * n; i++)
    {
        printf("%d ", mat[i / n][i % n]);
        if (i % n == n - 1)
            printf("\n");
    }
}