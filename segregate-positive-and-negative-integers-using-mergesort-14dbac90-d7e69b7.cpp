#include<bits/stdc++.h>
using namespace std;

int* merge(int arr[],int low,int high)
{
	for(int x=low;x<high;x++)
	{
		if(arr[x]<0)
			continue;
		for(int y=x+1;y<=high;y++)
		{
			if(arr[y]<0)
			{
				int temp=arr[y];
				arr[y]=arr[x];
				arr[x]=temp;
				break;
			}
		}
	}
	return arr;
}
int* mergesort(int arr[],int low,int high)
{
	int piv=(low+high)/2;
	if(low<high)
	{
		arr=mergesort(arr,low,piv);  //left rec
		arr=mergesort(arr,piv+1,high);//right rec
		arr=merge(arr,low,high); 
	}
	return arr;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int *array=mergesort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	return 0;
}