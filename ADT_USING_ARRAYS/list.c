#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_SIZE = 100, count = 0;
int *list;

int options()
{
    int choice;
    printf("\nPlease Enter Your Choice\n1)Insert last\n2)Insert between\n3)Delete\n4)Search\n5)Display\n");
    scanf("%d", &choice);
    if (choice > 0 && choice <= 5)
        return choice;
    else
    {
        printf("\nPlease Enter a Valid Choice\n");
        _sleep(1000);
        options();
    }
}

void search()
{
    int searchElement;
    printf("Please enter the element to search : ");
    scanf("%d",&searchElement);
    int i;
    for (i = 0; i < count; i++)
    {
        if (searchElement == list[i])
            printf("\n The Element %d is found in %d index", searchElement, i);
    }
    printf("=========================================================================\n");
}

void reallocate()
{
    realloc(list, (MAX_SIZE += 10) * sizeof(int));
}

void init()
{
    list = malloc(MAX_SIZE * sizeof(int *));
    memset(list, 0, sizeof(int));
    count = 0;
    MAX_SIZE = 100;
}

void insertlast(int val)
{
    if (count < MAX_SIZE)
    {
        list[count] = val;
        count++;
    }
    else
    {
        reallocate();
        list[count] = val;
        count++;
    }
}

void insertBetween(int val, int index)
{

    if (count < MAX_SIZE)
    {
        rearrange(index);
        list[index] = val;
        count++;
    }
    else
    {
        reallocate();
        rearrange(index);
        list[index] = val;
        count++;
    }
}

void rearrange(int index)
{
    if (count < MAX_SIZE && count > 0)
    {
        int i;
        for (i = count - 1; i >= index; i--)
        {
            list[i + 1] = list[i];
        }
    }
    else
    {
        reallocate();
    }
}

void regroup(int index)
{

    int i;
    for (i = index; i < count - 1; i++)
    {
        list[i] = list[i + 1];
    }
}

void delete (int index)
{
    int i;
    for (i = index; i < count - 1; i++)
    {
        list[i] = list[i + 1];
    }
}

void display()
{
    int i;
    for (i = 0; i < count; i++)
    {
        printf("%d ", list[i]);
    }
}

int main()
{
    init();
    while (1)
    {
        int choice = options();
        int val = 0, index = 0;
        switch (choice)
        {
        case 1:
            printf("\nPlease Enter the value to be inserted :");
            scanf("%d", &val);
            insertlast(val);
            printf("\nInserted Successfully");
            break;
        case 2:
            printf("\nPlease Enter the value and the position to be inserted :");
            scanf("%d %d", &val, &index);
            insertBetween(val, index);
            printf("\nInserted Successfully");
            break;
        case 3:
            printf("\nPlease Enter the index to be deleted :");
            scanf("%d", &index);
            delete (index);
            count--;
            printf("\nDeleted Successfully");
            break;
        case 4:
            search();
            break;
        case 5:
            display();
            break;
        default:
            break;
        }
    }
}