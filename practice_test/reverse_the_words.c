#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000],b[1000];
    scanf("%[^\n]s", a);
    strrev(a);
    int n = strlen(a),count=0;
    while(count<n-1)
    {
        sscanf(a+count, "%s", b);
        count += strlen(b)+1;
        strrev(b);
        printf("%s ",b);
    }
}