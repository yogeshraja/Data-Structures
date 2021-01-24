#include <stdio.h>

size_t binToGray(size_t binVal)
{
	if(binVal==0)
		return 0;
	int a=binVal%10;
	int b=(binVal/10)%10;
	if((a ^ b))
		return (1+10*binToGray(binVal/10));
	return (10*binToGray(binVal/10));
}
int main()
{
	size_t binary;
	scanf("%zu",&binary);
	printf("%zu",binToGray(binary));
}