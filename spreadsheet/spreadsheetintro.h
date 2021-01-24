#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**Invoking the MainChoice menu presents you with a list of options that you can convert From*/
int MainChoice()
{
    int mainChoice = 0;
    printf("===========================================================================WELCOME TO THE SPREADSHEET");
    printf("===========================================================================\n\n");
    printf("Please Enter Your Choice\nSelect The Number System You Would Like To Convert From\n1.)Decimal\n2.)Binary\n3.)Octal\n4.)HexaDecimal\n");
    scanf("%d", &mainChoice);
    if (mainChoice > 0 && mainChoice < 5)
    {
        return mainChoice;
    }
    else
    {
        printf("\nPlease Enter A Valid Choice\n");
        _sleep(1000);
        MainChoice();
    }
}
/**Invoking the subchoice menu presents you with a list of options that you can convert to*/
int SubChoice(int mainchoice)
{
    int subchoice = 0;
    switch (mainchoice)
    {
    case 1:
        printf("\nPlease Enter Your Choice\nSelect The Number System You Would Like To Convert To\n1.)Binary\n2.)Octal\n3.)HexaDecimal\n");
        scanf("%d", &subchoice);
        break;
    case 2:
        printf("\nPlease Enter Your Choice\nSelect The Number System You Would Like To Convert To\n1.)Decimal\n2.)Octal\n3.)HexaDecimal\n");
        scanf("%d", &subchoice);
        break;
    case 3:
        printf("\nPlease Enter Your Choice\nSelect The Number System You Would Like To Convert To\n1.)Binary\n2.)Deciaml\n3.)HexaDecimal\n");
        scanf("%d", &subchoice);
        break;
    case 4:
        printf("\nPlease Enter Your Choice\nSelect The Number System You Would Like To Convert To\n1.)Binary\n2.)Octal\n3.)Decimal\n");
        scanf("%d", &subchoice);
        break;
    }
    if (subchoice > 0 && subchoice < 4)
    {
        return subchoice;
    }
    else
    {
        printf("\nPlease Enter A Valid Choice\n");
        _sleep(1000);
        SubChoice(mainchoice);
    }
}
