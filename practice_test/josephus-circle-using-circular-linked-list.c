#include<stdio.h>
#include<stdlib.h>

struct circularll
{
	int data;
	struct circularll *next;
};

typedef struct circularll node;

node *last=NULL;

node* newNode(int val)
{
	node *newnode=(node *)malloc(sizeof(node));
	newnode->data=val;
	newnode->next=NULL;
	return newnode;
}

void insert(int val)
{
	node *newnode=newNode(val),temp;
	if(last==NULL)
	{
		last=newnode;
		last->next=last;
	}
	else
	{
		newnode->next=last->next;
		last->next=newnode;
		last=newnode;
	}
}

void circle(int m,int n)
{
	node *temp=last;
	while(n!=1)
	{
		for(int i=1;i<m;i++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		n--;
	}
	printf("%d",temp->data);
}

void display()
{
	node *temp=last->next;
	do{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=last);
	printf("%d",last->data);
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		insert(i);
	circle(m,n);
	return 0;
}