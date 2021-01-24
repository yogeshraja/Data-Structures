#include<stdio.h>
#include<stdlib.h>

struct queue{
	int data;
	struct queue *next;
};

typedef struct queue *node;

node front=NULL;

void enqueue(int val)
{
	node newnode;
	newnode=(node)malloc(sizeof(node));
	newnode->data=val;
	newnode->next=NULL;
	if(front==NULL)
	{
		front=(node)malloc(sizeof(node));
		front=newnode;	
	}
	else
	{
		node temp;
		temp=front;
		while(!temp->next==NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}

void dequeue()
{
	if(front==NULL)
	{
		printf("-1 ");	
	}
	else
	{
		printf("%d ",front->data);
		front=front->next;
	}
	
}


int main()
{
	int queries;
	scanf("%d",&queries);
	int x,y;
	for(int i=0;i<queries;i++)
	{
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d",&y);
			enqueue(y);
		}
		if(x==2)
		{
			dequeue();
		}
	}
	return 0;
}