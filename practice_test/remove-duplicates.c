#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct linkedList
{
	char data;
	struct linkedList *next;
};
typedef struct linkedList *node;

node head=NULL;

void removeDup()
{
	node temp,iterator,previous;
	previous=head;
	temp=head;
	while(!temp->next==NULL)
	{
		iterator=temp->next;
		
		while(1)
		{
			
			if(iterator->data==temp->data)
			{
				if(temp==head)
				{
					head=head->next;
					break;
				}
				else 
				{
					previous->next=temp->next;
					break;
				}

			}
			if(iterator->next==NULL)
			{
				break;
			}
			iterator=iterator->next;
		}
		previous=temp;
		temp=temp->next;		
	}
}

void insert(char c)
{
	node newnode;
	newnode=(node)malloc(sizeof(node));
	newnode->data=c;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=(node)malloc(sizeof(node));
		head=newnode;
	}
	else 
	{
		node temp;
		temp=head;
		while(!temp->next==NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}

int main()
{
	char c[100];
	scanf("%[^\n]c",&c);
	int i=0;
	while(c[i]!='\0')
	{
		if(c[i]!=' ')
			insert(c[i]);
		i++;
	}
	removeDup();
	node temp;
	temp=head;
	
	while(1)
	{
		printf("%c ",temp->data);
		if(temp->next==NULL)
			break;
		else
			temp=temp->next;
	}
}