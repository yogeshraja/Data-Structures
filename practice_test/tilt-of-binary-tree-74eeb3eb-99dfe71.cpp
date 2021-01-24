#include<bits/stdc++.h>
using namespace std;

struct btree
{
	int data,tilt;
	struct btree *left,*right;
	btree(int d):data{d},left{nullptr},right{nullptr},tilt{0}{};
};
typedef struct btree node;

node* readInput()
{
	int n;
	map<int,node*> mp;
	node* root=NULL;
	cin>>n;
	while(n--)
	{
		int n1,n2;
		char side;
		node* parent,*child;
		scanf("%d %d %c",&n1,&n2,&side);
		if(mp.find(n1)==mp.end())
		{
			mp[n1]=new btree(n1);
			parent=mp[n1];
			if(root==NULL)
			{
				root=mp[n1];
			}
		}
		else
		{
		parent=mp[n1];
		}
		child=new btree(n2);
		if(side=='L')
		{
			parent->left=child;
		}
		else
		{
			parent->right=child;
		}
		mp[n2]=child;
	}
	return root;
}

int findSum(node* root)
{
	if(!root)		return 0;

	return root->data+(findSum(root->left) + findSum(root->right));
}

void findTilt(node* root)
{
	if(!root)	return ;
	findTilt(root->left);
	findTilt(root->right);
	root->tilt=abs(findSum(root->left)-findSum(root->right));
}

int tiltTree(node* root)
{
	if(!root)		return 0;
	findTilt(root);
	return root->tilt+(tiltTree(root->left) + tiltTree(root->right));
}


int main()
{
	int t;
	cin>>t;
	while(t--)		cout<<tiltTree(readInput())<<endl;
}