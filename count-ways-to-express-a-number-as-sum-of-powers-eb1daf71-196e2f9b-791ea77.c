#include <stdio.h>
#include<math.h>
int countWays(int x,int n,int i)
{
	int remainder=(x - pow(i,n));
	if(remainder==0)
		return 1;
	if(remainder<0)
		return 0;
	if(i*i>x)
		return 0;
	return countWays(x,n,i+1)+countWays(remainder,n,i+1);
}
int main(){
	int x,n;
	scanf("%d",&x);
	scanf("%d",&n);
	printf("%d",countWays(x,n,1));
}

