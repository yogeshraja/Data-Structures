#include<stdio.h>
#include<stdlib.h>

struct circularll
{
	int data;
	struct circularll *next;
};

typedef struct circularll node;

node *last=NULL,*first=NULL;
node* newNode(int val)
{
	node *newnode=(node *)malloc(sizeof(node));
	newnode->data=val;
	newnode->next=NULL;
	return newnode;
}

void insert(int val)
{
	node *newnode=newNode(val);
	if(last==NULL)
	{
		last=newnode;
		last->next=last;
	}
	else
	{
		newnode->next=last->next;
		last->next=newnode;
	}
}

void display()
{
	node *temp=first;
	if(temp==NULL)
		return;
	do
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=first);
}

int isPrime(int n)
{
	int i;
	if (n <= 1)
		return 0;
	if(n<=3)
		return 1;
	if(n%2==0 || n%3 ==0)
		return 0;
	for(i=5;i*i<=n;i+=6)
	{
		if(n%i==0 || n%(i+2)==0)
			return 0;
	}
	return 1;
}

void deletePrimes(int n)
{
	int i=1;
	node *temp=last->next;
	node *old=last;
	n++;
	while (n--)
	{
		if(isPrime(temp->data))
		{
			if (temp == first)
			{
				first=first->next;
				if(first->next==first)
				{
					first=NULL;
				}
			}
			old->next=temp->next;
			temp=temp->next;
			continue;
		}
		old=temp;
		temp=temp->next;
	}
}

int main()
{
	int x,n,i;
	scanf("%d",&n);
	for( i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(x);
	}
	first=last->next;
	deletePrimes(n);
	display();
	return 0;
}