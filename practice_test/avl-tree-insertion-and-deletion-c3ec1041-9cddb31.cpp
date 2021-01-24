#include <bits/stdc++.h>
using namespace std;

struct avl
{
	int data,height;
	struct avl *left,*right;
	avl(int d):data{d},height{1},left{nullptr},right{nullptr}{};
};
typedef  struct avl node;

bool verifyTree(node* root)
{
	if(!root)	return true;
	if((root->left && root->data < root->left->data) || (root->right && root->data > root->right->data))
		return false;
	return (verifyTree(root->left) && verifyTree(root->right));
}

int height(node* root)
{
	if(!root)	return 0;
	return root->height;
}
int getBal(node* root)
{
	return height(root->left)-height(root->right);
}
node* rightRotation(node* A)
{
	node *B=A->left;
	node *NR=B->right;

	B->right=A;
	A->left=NR;

	A->height=1+max(height(A->left),height(A->right));
	B->height=1+max(height(B->left),height(B->right));
	return B;
}
node* leftRotation(node* A)
{
	node *B=A->right,*NR=B->left;

	B->left=A;
	A->right=NR;

	A->height=1+max(height(A->left),height(A->right));
	B->height=1+max(height(B->left),height(B->right));
	return B;
}
node* insert(node* root,int data)
{
	if(!root)	return (new avl(data));
	if(data<root->data)	root->left=insert(root->left,data);
	else	if(data>root->data)	root->right=insert(root->right,data);
	else	return NULL;

	root->height=1+max(height(root->left),height(root->right));

	int bal=getBal(root);
	if(bal>1 && data<root->left->data)
	{
		return rightRotation(root);
	}
	if(bal<-1 && data>root->right->data)
	{
		return leftRotation(root);
	}
	//LR
	if(bal>1 && data>root->left->data)
	{
		root->left=leftRotation(root->left);
		return rightRotation(root);
	}
	//RL
	if(bal<-1 && data<root->right->data)
	{
		root->right=rightRotation(root->right);
		return leftRotation(root);
	}
	return root;
}

void inorder(node* root)
{
	if(!root)	return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(node* root)
{
	if(!root)	return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(node* root)
{
	if(!root)	return ;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	node* root=NULL;
	int index=1;
	cin>>index;
	if(index==1)
	{
		int n=10;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int x;
			//cin>>x;
			root=insert(root,i+1);
		}
		cout << verifyTree(root) << endl;
		inorder(root);
		cout<<endl;
		preorder(root);
		cout<<endl;
		postorder(root);
		cout<<endl;
	}
	else
	{
		int n = 10;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x;
			//cin>>x;
			root = insert(root, i + 1);
		}
		int del;
		cin >> del;
		//root = deleteNode(root,del);
		preorder(root);
	}
}

/*
1
10
*/