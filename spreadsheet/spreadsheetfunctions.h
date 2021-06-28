#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * has one arguments and no return type 
 * prints the output directly to the console
 * converts DECIMAL to BINARY
 * */
void dectobin(int val)
{
    char binArr[100];
    int i = 0;
    while (val)
    {
        binArr[i++] = '0' + (val % 2);
        val /= 2;
    }
    strrev(binArr);
    printf("\n%s", binArr);
}
/**
 * has one arguments and no return type 
 * prints the output directly to the console
 * converts DECIMAL to OCTAL
 * */

void dectooct(int val)
{
    printf("\n%o", val);
}
/**
 * has one arguments and no return type 
 * prints the output directly to the console
 * converts DECIMAL to HEXA DECIMAL
 * */

void dectohex(int val)
{

    printf("%x", val);
}

int bintodec(char arr[], int n)
{
    int basecount = 1, decimalvalue = 0;
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        printf("%c ", arr[i]);
        if (arr[i] == '1')
            decimalvalue += basecount;
        basecount = basecount * 2;
    }
    return decimalvalue;
}