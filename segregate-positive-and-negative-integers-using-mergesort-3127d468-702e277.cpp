// while(flag)
	// {
	// 	flag=0;
	// 	if(x<=piv && arr[x]<0)
	// 	{
	// 		array[i++]=arr[x++];
	// 		flag=1;
	// 	}	
	// 	else
	// 	{
	// 		if(y<=high && arr[y]<0)
	// 		{
	// 			array[i++]=arr[y++];
	// 			flag=1;
	// 		}
	// 	}

	// }

#include <bits/stdc++.h>
using namespace std;

int* merge(int arr[],int low,int high,int piv)
{
	int array[high-low+1];
	int x=low,y=piv+1;
	int i=0,flag=1;
	
	while(x<=piv && arr[x]<0)
	{
		array[i++]=arr[x++];
	}
	while(y<=high && arr[y]<0)
	{
		array[i++]=arr[y++];
	}
	while(x<=piv)
	{
		array[i++]=arr[x++];
	}
	while(y<=high)
	{
		array[i++]=arr[y++];
	}
	return array;
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
	for(int i=low;i<high;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return arr;
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int *arr=mergeSort(a,0,n-1);
	// for(int i=0;i<n;i++)
	// 	cout<<arr[i]<<" ";
}
