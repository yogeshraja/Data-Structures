#include <stdio.h>
#include <malloc.h>

struct doublyLinkedList
{
    int data;
    struct doublyLinkedList *next;
    struct doublyLinkedList *previous;
};

typedef struct doublyLinkedList node;

node *head = NULL;
int count = 0;

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

node* newNode(int val)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->previous = NULL;
    return newnode;
}

void insert(int val)
{
    node *temp;
    node *newnode = newNode(val);
    temp = head;
    if(head==NULL)
    {
        head = newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        newnode->previous = temp;
        temp->next = newnode;
    }
    
}

void insertBetween(int val,int index)
{
    int i=0;
    node *temp;
    node *newnode = newNode(val);
    temp = head;
    if (i==0)
    {
        head->previous = newnode;
        newnode->next = head;
        head = newnode;
    }
    else
    {
        while (i<index)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next->previous = newnode;
        temp->next = newnode;
        newnode->previous = temp;
    }
}

void search()
{
    int searchElement;
    printf("Please enter the element to search : ");
    scanf("%d", &searchElement);
    int i=0;
    node *temp = head;
    while(temp!=NULL)
    {
        if (searchElement == temp->data)
            printf("\n The Element %d is found in %d index", searchElement, i);
        i++;
        temp = temp->next;
    }
    printf("\n=========================================================================\n");
}

void display()
{
    node *temp = head;
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void delete(int index)
{
    int i = 0;
    node *temp=head;
    while(i<index && temp!=NULL)
    {
        temp = temp->next;
        i++;
    }
    if(temp==head)
    {
        head = head->next;
        head->previous = NULL;
    }
    else
    {
        if(temp->next->next!=NULL)
        {
            temp->next = temp->next->next;
            temp->next->next->previous = temp;
        }
        else
        {
            temp->next = NULL;
        }
        
    }
    
}

// void input(int n, node **head)
// {
//     int val, i;
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &val);
//         insert(head, val);
//     }
// }

int main()
{
    
    printf("%d", sizeof(node));
    while (1)
    {
        int choice = options();
        int val = 0, index = 0;
        switch (choice)
        {
        case 1:
            printf("\nPlease Enter the value to be inserted :");
            scanf("%d", &val);
            insert(val);
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