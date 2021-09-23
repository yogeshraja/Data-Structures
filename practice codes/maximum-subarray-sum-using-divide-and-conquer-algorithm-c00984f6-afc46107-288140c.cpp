#include <bits/stdc++.h>
using namespace std;
int findMax(int a, int b)
{
	return (a>b?a:b);
}
int findSum(int arr[],int start,int end,int n)
{
	int sum=0;
	for(int i=start;i<=end;i++)
		sum+=arr[i];
	if(end<0 || start>n)
		return sum;
	
	return findMax(sum,findMax(findSum(arr,start+1,end,n),findSum(arr,start,end-1,n)));
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Maximum contiguous sum is "<<findSum(a,0,n-1,n);
}.........