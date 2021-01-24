#include <stdio.h>
int coins(int a[], int tot, int mila, int gila, int count)
{
    int first = a[count];
    if ((tot - first) == (mila + first))
        return 1;
    else if (count > gila)
        return 0;
    else
    {
        return coins(a, tot, mila, gila, count + 1);
    }
}
int main()
{
    int test, gila, mila;
    scanf("%d", &test);
    for (int t = 0; t < test; t++)
    {
        scanf("%d", &gila);
        scanf("%d", &mila);
        int a[gila], tot = 0;
        for (int i = 0; i < gila; i++)
        {
            scanf("%d", &a[i]);
            tot = tot + a[i];
        }
        int count = 0;
        int x = coins(a, tot, mila, gila, count);
        if (x == 1)
            printf("1\n");
        else
            printf("0\n");
    }
}