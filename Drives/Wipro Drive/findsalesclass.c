#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n>=30 && n<=50){
        printf("D");
    }
    else if (n >= 51 && n <= 60)
    {
        printf("C");
    }
    else if(n >= 61 && n <= 80)
    {
        printf("B");
    }
    else if (n >= 81 && n <= 100)
    {
        printf("A");
    }
    return 0;
}