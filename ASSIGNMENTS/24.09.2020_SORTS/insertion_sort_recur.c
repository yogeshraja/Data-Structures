#include <stdio.h>
int* insetionSort(int arr[],int j,int key)
{
    if(j<0 && arr[j]<key)
    {
        arr[j + 1] = key;
        return arr;
    }
        
    arr[j + 1] = arr[j];
    return insetionSort(arr, j - 1, key);
}
int* getInserSort(int arr[],int n)
{
    int i,key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        arr = insetionSort(arr, j, key);
    }
    return arr;
}
int main()
{
    int n;
    scanf("%d", &n);
    int i = 0, arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int *array = getInserSort(arr,n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}