#include <stdio.h>
#include <stdlib.h>

struct linkedList
{
    int data;
    struct linkedList *next;
};
typedef struct linkedList *node;


node head1 = NULL;
node head2 = NULL;

void insert(node head, int val)
{
    node newnode;

    newnode = (node)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = (node)malloc(sizeof(node));
        head = newnode;
    }
    else
    {
        node temp;
        temp = head;
        while (temp->next == NULL)
        {
            temp = temp->next;
        }
        temp = newnode;
    }
}

void input(int n, node list)
{
    int val,i;
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insert(list, val);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        input(n, &head1);
        scanf("%d", &n);
        input(n, &head2);
    }

    node temp;
    temp = head1;
    printf("Enter While");
    while (temp!= NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}