#include<stdio.h>
enum months
{
    January=31,
    February=59,
    March=90,
    April=120,
    May=151,
    June=181,
    July=212,
    August=243,
    September=273,
    October=304,
    November=334,
    December=365
};
int main()
{
    for (int i = January; i != December;i++)
    {
        printf("%d", i);
    }
}