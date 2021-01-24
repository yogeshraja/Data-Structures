#include<stdio.h>
#include<string.h>

char* removeDup(char a[],int iterator,int flag,int n)
{
	
	if(iterator==n)
		return a;
	if(a[iterator]==a[iterator+1])
	{
		a[iterator]=0;
		return removeDup(a,iterator+1,1,n);
	}
	if(flag)
	{
		a[iterator]=0;
		return removeDup(a,iterator,0,n);
	}
	return removeDup(a,iterator+1,0,n);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char a[50];
		memset(a,0,50);
		scanf("%s",a);
		int n=strlen(a);
		char *x=removeDup(a,0,0,n);
		for(int i=0;i<n;i++)
		{
			if(x[i]!=0)
			printf("%c",a[i]);
		}
		printf("\n");
	}
}
