#include <stdio.h>
#include <stdlib.h>
int main()
{
    void *x[3];
    int a = 10;
    float b = 12.64;
    char c = 's';
    x[0] = &a;
    x[1] = &b;
    x[2] = &c;
    printf("%d\n", *(int *)x[0]);
    printf("%f\n", *(float *)x[1]);
    printf("%c\n", *(char *)x[2]);
}D