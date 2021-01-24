#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node *node;

node head = NULL,last=NULL;

void append(int data)
{
    if (head == NULL)
    {
        node newnode = (node)malloc(sizeof(node));
        newnode->data = data;
        head = newnode;
        head->next = head;
        last = head;
    }
    else
    {
        node newnode = (node)malloc(sizeof(node));
        newnode->data = data;
        newnode->next = last->next;
        last->next = newnode;
        last = newnode;
    }
}
void deletew(n)
{
    node temp = head, old;
    while(n--)
    {

        int d = 0,i;
        d = temp->data;
        //printf("%d", d);
        int flag = 0;
        for ( i = 1; i <= d; ++i)
        {
            if ((d % i) == 0)
            {
                flag++;
            }
        }
        if (flag == 2)
        {
            if (temp == head)
            {
                node del = temp;
                temp = temp->next;
                head = head->next;
                last->next = head;
                free(del);
                continue;
            }
            node del = temp;
            old->next = temp->next;
            temp = temp->next;
            free(del);
            continue;
        }
        old = temp;
        temp = temp->next;
    }
}
void print()
{
    node temp = head;

    if (temp == NULL)
    {
        printf("List is empty");
        return;
    }
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
int main()
{

    int n;
    scanf("%d\n", &n);
    int arr[n], i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        append(arr[i]);
    }
    deletew(n);
   print();
}