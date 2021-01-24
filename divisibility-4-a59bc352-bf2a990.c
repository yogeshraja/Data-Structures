#include <stdio.h>

int divCheck(int arr[], int val, int iterator, int n)
{
	if (iterator == n)
		return 0;
	if (val % arr[iterator] == 0)
		return 1;
	return divCheck(arr, val, ++iterator, n);
}

int divisibility(int arr[], int k, int n)
{
	int count = 0;
	for (int i = 1; i <= k; i++)
	{
		count += divCheck(arr, i, 0, n);
	}
	return count;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int userArray[n];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &userArray[i]);
		}
		int k;
		scanf("%d", &k);
		int x = divisibility(userArray, k, n);
		printf("%d\n",x );
	}
}