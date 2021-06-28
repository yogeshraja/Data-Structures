#include <stdio.h>
#include <stdlib.h>

void createlist();
void display();

struct list
{
    int data;
    struct list *next, *prev;
};

typedef struct list node;

node *head = NULL, *temp = NULL, *tail = NULL;

int main()
{
    printf("Hello, World!\n");
    createlist();
    display();

    return 0;
}

void createlist()
{
    int s, i;
    scanf("%d", &s);
    for (i = 0; i < s; i++)
    {
        int k;
        scanf("%d", &k);
        node *newnode = (node *)malloc(sizeof(node));
        newnode->data = k;
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL)
        {
            head = newnode;
            head->next = head;
            head->prev = head;
            temp = head;
        }
        else
        {
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next = newnode;
            temp = temp->next;
        }
        head->prev = temp; // CLL
        temp->next = head;
    }

    temp = head;
    int j;
    for (j = 0; j < s; j++)
    {
        int check = 0;
        int t = temp->data;

        for (i = 1; i <= t; i++)
        {
            if (t % i == 0)
            {
                check++;
            }
        }

        if (check == 2)
        {
            if (temp == head)
            {
                head = temp->next;
            }
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
        }
        temp = temp->next;
    }
}

void display()
{
    temp = head->prev;
    do
    {
        printf("%d ", temp->data); //CLL
        temp = temp->prev;
    } while (temp != head->prev);
}