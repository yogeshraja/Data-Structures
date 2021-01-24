#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
	char data;
	struct stack *next;

};

typedef struct stack *node;

// node newNode(char x)
// {
// 	node newnode;
// 	newnode=(node)malloc(sizeof(node));
// 	newnode->data=x;
// 	newnode->next=NULL;
// }

node top=NULL;

void display()
{
	node temp=top;
	while(!temp==NULL)
	{
		printf("%c",temp->data);
		temp=temp->next;
	}
}

void push(char x)
{
	node newnode=(node)malloc(sizeof(node));
	newnode->data=x;
	newnode->next=NULL;
	if(top==NULL)
	{
		top=newnode;
	}
	else{
	newnode->next=top;
	top=newnode;
	}
}
char pop()
{
	if(top==NULL)
	{
		return 'x';
	}
	char t;
	t=top->data;
	top=top->next;
	return t;
}

int main()
{
	int inputs;
	scanf("%d",&inputs);
	getchar();
	while(inputs--)
	{
		char values[1000];
		scanf("%s",values);
		int n=strlen(values);
		int flag=1,i;
		for( i=0;i<n;i++)
		{
			if(values[i]=='{' || values[i]=='[' || values[i]=='(')
			{
				push(values[i]);
			}
			if(values[i]=='}' || values[i]==']' || values[i]==')')
			{
				char test=pop();
				//printf("%c %c",test,values[i]);
				if(values[i]==')')
				{
					if(!(test=='('))
					{
						flag=0;
						break;
					}
				}
				if(values[i]=='}')
				{
					if(!(test=='{'))
					{
						flag=0;
						break;
					}
				}
				if(values[i]=='[')
				{
					if(!(test==']'))
					{
						flag=0;
						break;
					}
				}
				
			}
		}
		if(top!=NULL)
		{
			flag=0;
		}
		if(flag)
		{
			printf("balanced\n");
		}
		else
		{
			printf("not balanced\n");
		}

	}
}