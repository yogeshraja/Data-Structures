#include<bits/stdc++.h>
using namespace std;

struct tree
{
	string data;
	struct tree *left,*right;
	tree(string d):data{d},left{nullptr},right{nullptr}{}
};

typedef struct tree node;

node *root=NULL;
 
void insert(string d)
{
	if(!root)
	{
		root=new tree(d);
	}
	else
	{
		node *temp;
		queue <node *> q;
		q.push(root);
		while(!q.empty())
		{
			temp=q.front();
			q.pop();
			if(temp->data=="N") continue;
			if(!temp->left)
			{
				temp->left=new tree(d);
				break;
			}
			else
				q.push(temp->left);
			if(!temp->right)
			{
				temp->right=new tree(d);
				break;
			}
			else
				q.push(temp->right);
		}
	}
}

void printLevel(node* root)
{
	node *temp;
	queue <node *> q;
	q.push(root);
	while(!q.empty())
		{
			temp=q.front();
			q.pop();

			//if(temp->data=="N") continue;
			cout<<temp->data<<" ";
			if(!temp->left)
			{
				continue;
			}
			else
				q.push(temp->left);
			if(!temp->right)
			{
				continue;
			}
			else
				q.push(temp->right);
		}
}
void makeNull()
{
	node *temp;
	queue <node *> q;
	q.push(root);
	while(!q.empty())
		{
			temp=q.front();
			q.pop();
			if(temp->data=="N") { temp=NULL; continue;};
			if(!temp->left)	{continue;}
			else q.push(temp->left);
			if(!temp->right) {continue;}
			else q.push(temp->right);
		}
}
void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		if(root->data!="N") cout<<root->data<<" ";
		inorder(root->right);
	}
}

node* rotateTree(node* rootnode)
{
	if(rootnode == NULL)
	{
		return rootnode;
	}

	if(rootnode->left==NULL && rootnode->right==NULL)
	{
		return root;
	}

	if(rootnode->left->data=="N" && rootnode->right->data=="N")
	{
		return root;
	}

	node* tempRoot=rotateTree(rootnode->left);
	rootnode->left->left=rootnode->right;
	rootnode->left->right=rootnode;
	rootnode->left=rootnode->right=NULL;

	return tempRoot;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char a[1000]={0};
		scanf(" %[^\n]s",a);
		int n=strlen(a);
		for(int i=0;i<n;i++)
		{
			string s="";
			while(a[i]!=' ' && i<n)
			{
				s+=a[i++];
			}
			insert(s);
		}
		makeNull();
		root=rotateTree(root);
		//printLevel(root);
		inorder(root);
		cout<<endl;
		root=NULL;
	}
	return 0;
}