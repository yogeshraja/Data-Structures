#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct doublyLinkedList
{
    int data;
    struct doublyLinkedList *previous;
    struct doublyLinkedList *next;
};

typedef struct doublyLinkedList listNode;

struct ternaryTree
{
    int data;
    struct ternaryTree *left;
    struct ternaryTree *middle;
    struct ternaryTree *right;
};

typedef struct ternaryTree treeNode;

listNode *newNode(int value)
{
    listNode *newnode = (listNode *)malloc(sizeof(listNode));
    newnode->data = value;
    newnode->previous = NULL;
    newnode->next = NULL;
    return newnode;
}

void insert(listNode **head, int value)
{
    listNode *temp, *newnode = newNode(value);
    temp = *(head);
    if (*(head) == NULL)
    {
        *(head) = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode->previous = temp;
        temp->next = newnode;
    }
}

int countSpace(char a[])
{
    int n = strlen(a), size = 0, i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == ' ')
        {
            size++;
        }
    }
    return ++size;
}

int getLevelvalue(int level)
{
    int i, p = 0;
    for (i = 1; i <= level; i++)
    {
        p = p * 3 + 1;
    }
    return p;
}

int findLevels(int size)
{
    int p = 1;
    if (size == 1)
        return 1;
    int i;
    for (i = 2; i < 10; i++)
    {
        p = p * 3 + 1;
        if (p == size)
        {
            return i;
        }
    }
}

void extractNumbers(int *userArray, char input[])
{
    int k = 0, i;
    for (i = 0; input[i] != '\0'; i++)
    {
        int val = 0;
        if (input[i] >= '0' && input[i] <= '9')
        {
            while (input[i] >= '0' && input[i] <= '9')
            {
                int x = input[i] - '0';
                val = val * 10 + x;
                i++;
            }
            userArray[k++] = val;
        }
    }
}

void treetolist(int userarray[], int level, int size,int n)
{
    if (level == 0)
    {
        return;
    }
    else
    {
        int i, skip = getLevelvalue(level),alter=getLevelvalue(level+1);
        if(level<=n-2)
        {
            i = size - alter;
        }
        else
        {
            i = skip - 1;
        }
        
        for (; i < size; i += skip)
        {
            printf("%d ", userarray[i]);
            treetolist(userarray, level - 1, i,n);
        }
    }
}

int main()
{
    listNode *list = NULL;
    char input[1000];
    scanf("%[^\n]s", &input);
    int size = countSpace(input);
    int userArray[size];
    extractNumbers(userArray, input);
    listNode *levelledList = NULL;
    treetolist(userArray, findLevels(size), size, findLevels(size));
    return 0;
}