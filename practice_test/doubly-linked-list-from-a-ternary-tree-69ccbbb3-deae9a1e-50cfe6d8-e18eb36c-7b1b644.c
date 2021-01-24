#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct doublyLinkedList
{
	int data;
	struct doublyLinkedList *previous;
	struct doublyLinkedList *next;
};

typedef struct doublyLinkedList node;

node* newNode(int value)
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->data=value;
	newnode->previous=NULL;
	newnode->next=NULL;
	return newnode;
}

void insert(node **head,int value)
{
	node *temp,*newnode=newNode(value);
	temp=*(head);
	if(*(head)==NULL)
	{
		*(head)=newnode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		newnode->previous=temp;
		temp->next=newnode;
	}
}

int countSpace(char a[])
{
	int n=strlen(a),size=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==' ')
		{
			size++;
		}
	}
	return ++size;
}

void extractNumbers(int *userArray,char input[])
{
	int k=0;
	for(int i=0;input[i]!='\0';i++)
	{
		int val=0;
		if(input[i]>='0' && input[i]<='9')
		{
			while(input[i]>='0' && input[i]<='9')
			{
				int x=input[i]-'0';
				val=val*10+x;
				i++;
			}
			userArray[k++]=val;
		}
	}
}


int main()
{
	node *list=NULL;
	char input[1000];
	scanf("%[^\n]s",&input);
	int size=countSpace(input);
	int userArray[size];
	// size--;
	extractNumbers(userArray,input);
	if(size>4)
	insert(&list,userArray[--size]);
	for(int i=3;size>0;i=i+4)
	{
		insert(&list,userArray[i]);
		size--;
		for(int j=i-3;j<i;j++)
		{
			insert(&list,userArray[j]);
			size--;
		}
	}
	node *temp=list;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	return 0;
}