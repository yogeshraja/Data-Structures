/**
node *root=NULL;

void insert(string str)
{
	if(str[0]=='N' || str.length()==0)	return ;
	istringstream is(str);
	vector<string> v;
	int i=1;
	for(string str;is>>str;)
		v.push_back(str);
	queue<node*>q;
	root=new btree(stoi(v[0]));
	q.push(root);
	while(!q.empty() && i<v.size())
	{
		node* temp=q.front();
		q.pop();
		if(v[i]!="N")
		{
			temp->left=new btree(stoi(v[i++]));
			q.push(temp->left);
		}
		if(i>=v.size())	break;
		if(v[i]!="N")
		{
			temp->right=new btree(stoi(v[i++]));
			q.push(temp->right);
		}
	}
}*/

#include<bits/stdc++.h>
using namespace std;

struct btree
{
	int data;
	struct btree *left,*right;
	btree(int d):data{d},left{nullptr},right{nullptr}{};
};

typedef struct btree node;


void inorder(node* root)
{
	if(!root)	return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int lis(node* root)
{
	if(!root)	return 0;
	int incl,excl;
	excl=lis(root->left)+lis(root->right);
	incl=1;
	if(root->left)
		incl+=lis(root->left->left)+lis(root->left->right);
	if(root->right)
		incl+=lis(root->right->left)+lis(root->right->right);
	return max(incl,excl);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		//getchar();
		map <int,node*> mp;
		node* root=NULL;
		int n;
		cin>>n;
		//cout<<n<<"--";
		while(n--)
		{
			int n1,n2;
			char side;
			node *pt,*child;
			scanf("%d %d %c",&n1,&n2,&side);
			if(mp.find(n1)==mp.end())
			{
				pt=new btree(n1);
				mp[n1]=pt;
				if(!root)	root=pt;
			}
			else
				pt=mp[n1];
			child=new btree(n2);
			if(side=='L')
				pt->left=child;
			else
				pt->right=child;
			mp[n2]=child;
		}
		cout<<lis(root)<<endl;
	}
	
}