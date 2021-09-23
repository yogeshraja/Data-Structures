#include <stdio.h>
int NON_SINGLETON_ACCESS=0;

size_t binToGray(size_t binVal)
{
	NON_SINGLETON_ACCESS++;
	if(binVal==0)
		return 0;
	int a=binVal%10;
	int b=(binVal/10)%10;
	NON_SINGLETON_ACCESS++;
	if((a ^ b))
	{
		NON_SINGLETON_ACCESS++;
		return (1+10*binToGray(binVal/10));
	}
	NON_SINGLETON_ACCESS++;
	return (10*binToGray(binVal/10));
}
int main()
{
	size_t binary;
	scanf("%zu",&binary);
	NON_SINGLETON_ACCESS++;
	printf("%zu",binToGray(binary));
	NON_SINGLETON_ACCESS+=2;
	printf("\n%d",NON_SINGLETON_ACCESS);
}