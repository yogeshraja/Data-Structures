#include<bits/stdc++.h>
using namespace std;
int* merge(int arr[],int low,int high,int piv)
{
	cout<<"hii"<<high<<" "<<low<<endl;
	int a[high-low+1];
	int x=low,y=piv+1,i=0;
	while(x<=piv && y<= high)
	{
		if(arr[x]<arr[y])
		{
			a[i++]=arr[x++];
		}
		else
		{
			a[i++]=arr[y++];
		}
	}
	while(x<=piv)
	{
		a[i++]=a[x++];
	}
	while(y<=high)
	{
		a[i++]=a[y++];
	}
	return a;
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
int main()
{
	int n;
	int a[100],i=0;
	while((scanf("%d",&n))!=-1)
	{
		a[i++]=n;
	}
	cout<<i<<endl;
	int *arr=mergeSort(a,0,i);
	for(int x=0;x<i;x++)
	{
		cout<<a[x]<<" ";
	}
}
