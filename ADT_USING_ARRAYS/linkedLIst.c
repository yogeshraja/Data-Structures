#include<stdio.h>
#include<stdlib.h>

struct linkedList
{
    int data;
    struct linkedList *next;
};
typedef struct linkedList *node;

node head;
node last;

void init()
{
    int val;
    head = (node)malloc(sizeof(node));
    printf("\nPlease enter atleast one data to begin with");
    scanf("%d", &val);
    head->data = val;
    head->next = NULL;
    last = head;
}

void insertAfter(int position)
{
    node temp,newnode;
    int val;
    newnode = (node)malloc(sizeof(node));
    printf("Enter the data to be inserted ");
    scanf("%d", &val);
    newnode->data = val;
    temp = head;
    if(temp->data==position)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        temp = temp->next;
    }
    
}

void insertBefore(int position)
{
    int val;
    node temp, newnode;
    newnode = (node)malloc(sizeof(node));
    printf("Enter the data to be inserted ");
    scanf("%d", &val);
    newnode->data = val;
    temp = head;
    if (temp->next->data == position)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else
    {
        temp = temp->next;
    }
}

void insert()
{
    int val;
    node newnode;
    newnode = (node)malloc(sizeof(node));
    printf("\nPlease enter the value ");
    scanf("%d", &val);
    newnode->data = val;
    newnode->next = NULL;
    last->next = newnode;
    last = newnode;
}

int main()
{
    
}