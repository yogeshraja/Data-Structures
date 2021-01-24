#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int i = 0,array[n];
    for ( i = 0; i < n;i++)
    {
        scanf("%d", &array[i]);
    }
    int flag = 1;
    while (flag)
    {
        flag = 0;
        for (i = 0; i < n;i++)
        {
            if(array[i]>array[i+1])
            {
                flag = 1;
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}