#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct doublyLinkedList
{
    int data;
    struct doublyLinkedList *previous;
    struct doublyLinkedList *next;
};

typedef struct doublyLinkedList listNode;

// struct ternaryTree
// {
// 	int data;
// 	struct ternaryTree *left;
// 	struct ternaryTree *middle;
// 	struct ternaryTree *right;
// };

// typedef struct ternaryTree treeNode;

// void extractNumbers(int *userArray,char input[])
// {
// 	int k=0,i;
// 	for(i=0;input[i]!='\0';i++)
// 	{
// 		int val=0;
// 		if(input[i]>='0' && input[i]<='9')
// 		{
// 			while(input[i]>='0' && input[i]<='9')
// 			{
// 				int x=input[i]-'0';
// 				val=val*10+x;
// 				i++;
// 			}
// 			userArray[k++]=val;
// 		}
// 	}
// }

//int countSpace(char a[])
// {
// 	int n=strlen(a),size=0,i;
// 	for(i=0;i<n;i++)
// 	{
// 		if(a[i]==' ')
// 		{
// 			size++;
// 		}
// 	}
// 	return ++size;
// }

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

int getLevelValue(int level)
{
    int i, p = 0;
    for (i = 1; i <= level; i++)
    {
        p = p * 3 + 1;
    }
    return p;
}

int findLevel(int size)
{
    int p = 1, i;
    if (size == 1)
        return 1;
    for (i = 2; i < 10; i++)
    {
        p = p * 3 + 1;
        if (p == size)
        {
            return i;
        }
    }
}

void treeToList(listNode **list, int userArray[], int level, int size, int n)
{
    if (level == 0)
    {
        return;
    }
    else
    {
        int i, skip = getLevelValue(level), alter = getLevelValue(level + 1);
        if (n != level)
        {
            i = size - pow(3, level);
        }
        else
        {
            i = skip - 1;
        }
        for (; i < size; i += skip)
        {
            insert(list, userArray[i]);
            treeToList(list, userArray, level - 1, i, n);
        }
    }
}

int main()
{
    listNode *list = NULL;
    long int count = 0, MAX_SIZE = 100;
    char c = 'a';
    int *userArray;
    userArray = (int *)malloc(MAX_SIZE * sizeof(int));
    while (c != '\n')
    {
        if (count >= MAX_SIZE)
        {
            realloc(userArray, (MAX_SIZE += 100) * sizeof(int));
        }
        int val = 0;
        while ((c = getchar()) != '\n' && c != ' ')
        {
            if (c != ' ')
            {
                val = (val * 10) + (c - '0');
            }
        }
        userArray[count++] = val;
    }

    int size = count;
    treeToList(&list, userArray, findLevel(size), size, findLevel(size));
    listNode *temp = list;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}