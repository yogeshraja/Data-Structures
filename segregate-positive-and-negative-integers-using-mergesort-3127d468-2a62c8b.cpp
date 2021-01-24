#include <bits/stdc++.h>
using namespace std;

int* merge(int arr[],int low,int high,int piv)
{
	for(int x=low;x<=high;x++)
	{
		int key=arr[x];
		if(arr[x]>0)
			continue;
		int y=x-1;
		while(y>=0 && arr[y]>0)
		{
			arr[y+1]=arr[y];
			y--;
		}
		arr[y+1]=key;
	}
	return arr;
}

int* mergeSort(int arr[],int low,int high)
{
	int piv=(low+high)/2;
	if(low<high)
	{
		arr=mergeSort(arr,low,piv);
		arr=mergeSort(arr,piv+1,high);
		arr=merge(arr,low,high,piv);
	}
	return arr;
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int *arr=mergeSort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}
