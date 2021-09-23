#include<bits/stdc++.h>
using namespace std;
struct bTree
{
	string data;
	struct bTree *right,*left;
	bTree(string d): data{d},right{nullptr},left{nullptr}{} 
};

typedef struct bTree node;

node *root=NULL;

void insert(string str[],int n)
{
	int i=0;
	root=new bTree(str[i]);
	queue<node *> q;
	q.push(root);
	while(i<n && !(q.empty()))
	{
		node *temp=q.front();
		q.pop();
		if(str[++i]!="N" && i<n)
		{
			temp->left=new bTree(str[i]);
			q.push(temp->left);
		}
		if(!(i<n))
			break;
		if(str[++i]!="N" && i<n)
		{
			temp->right=new bTree(str[i]);
			q.push(temp->right);
		}
	}
}
void inorder(node *root)
{
	if(!root)
		return ;
	
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
	
}
void zigzag(node* root)
{
	string s="";
	s+=root->data;
	queue <node *> q;
	q.push(root);
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		if(temp->right!=NULL)
		{
			s+=" "+temp->right->data;
			q.push(temp->right);
		}
		if(temp->left!=NULL)
		{
			s+=" "+temp->left->data;
			q.push(temp->left);
		}
	}
	cout<<s<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char a[1000];
		string str[100];
		int k=0;
		scanf(" %[^\n]s",a);
		int n=strlen(a);
		for(int i=0;i<n;i++)
		{
			string s="";
			while(a[i]!=' ' && i<n)
			{
				s+=a[i++];
			}
			str[k++]=s;
		}
		insert(str,k);
		zigzag(root);
		// inorder(root);
		root=NULL;
	}
}