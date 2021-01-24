#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "spreadsheetintro.h"
#include "spreadsheetfunctions.h"

void invokeFunctions(int mainchoice, int subchoice)
{
    int val;
    char arr[100];
    switch (mainchoice)
    {
    case 1:
        switch (subchoice)
        {
        case 1:
            printf("Enter the decimal value : ");
            scanf("%d", &val);
            dectobin(val);
            break;
        case 2:

            printf("Enter the decimal value : ");
            scanf("%d", &val);
            dectooct(val);
            break;
        case 3:
            printf("Enter the decimal value : ");
            scanf("%d", &val);
            dectohex(val);
            break;
        }
        break;
    case 2:
        switch (subchoice)
        {
        case 1:
            
            printf("\nPlease Enter the BINARY VALUES :");
            gets(arr);
            printf("\n%d", bintodec(arr,strlen(arr)));
            break;
        case 2:
            printf("\nPlease Enter the BINARY VALUES :");
            gets(arr);
            printf("\n%o", bintodec(arr, strlen(arr)));
            break;
        case 3:
            printf("\nPlease Enter the BINARY VALUES :");
            gets(arr);
            printf("\n%x", bintodec(arr, strlen(arr)));
            break;
        }
        break;
    case 3:
        switch (subchoice)
        {
        case 1:
            printf("Enter the Octal value : ");
            scanf("%o", &val);
            dectobin(val);
            break;
        case 2:
            printf("Enter the Octal value : ");
            scanf("%o", &val);
            printf("\n%d", val);
            break;
        case 3:
            printf("Enter the Octal value : ");
            scanf("%o", &val);
            dectohex(val);
            break;
        }
        break;
    case 4:
        switch (subchoice)
        {
        case 1:
            printf("Enter the HexaDecimal value : ");
            scanf("%x", &val);
            dectobin(val);
            break;
        case 2:
            printf("Enter the HexaDecimal value : ");
            scanf("%x", &val);
            printf("\n%o", val);
            break;
        case 3:
            printf("Enter the HexaDecimal value : ");
            scanf("%x", &val);
            printf("%d", val);
            break;
        }
        break;
    }
}

int main()
{
    int choice=1;
    while (choice==1)
    {
        int mainchoice = MainChoice();
        int subchoice = SubChoice(mainchoice);
        invokeFunctions(mainchoice, subchoice);
        printf("\nWould you like to continue \n1) Yes\n2) No\n");
        scanf("%d", &choice);
    }
    return 0;
}
