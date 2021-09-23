#include <stdio.h>

int divCount(int arr[],int x,int k,int n)
{
	if(x==k+1)
		return 0;
	int flag=1;
	for(int i=0;i<n;i++)
	{
		if(x%arr[i]==0)
		{
			return (1+divCount(arr,x+1,k,n));
		}
	}
	return (0+divCount(arr,x+1,k,n));
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int size;
		scanf("%d",&size);
		int userArray[size];
		for(int i=0;i<size;i++)
		{
			scanf("%d",&userArray[i]);
		}
		int last;
		scanf("%d",&last);
		printf("%d\n",divCount(userArray,1,last,size));
	}
}

