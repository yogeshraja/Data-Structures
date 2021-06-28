#include <stdio.h>
int flag;
int *bubblesort(int a[], int n, int iterator)
{
    if (iterator % n == 0 && iterator != 0)
        return a;
    int it = iterator % n - 1, it1 = it + 1;
    if (a[it] > a[it1])
    {
        flag = 1;
        int temp = a[it1];
        a[it1] = a[it];
        a[it] = temp;
    }
    flag = 0;
    a = bubblesort(a, n, iterator + 1);
    if (flag == 0)
        return a;
    return bubblesort(a, n, 0);
}

int main()
{
    int n;
    scanf("%d", &n);
    int i = 0, array[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    int flag = 1, *arr = bubblesort(array, n, 0);
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}