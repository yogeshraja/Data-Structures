#include<bits/stdc++.h>
using namespace std;

struct bTree 
{
	int data;
	struct bTree *left,*right;
	bTree(int d):data{d},left{nullptr},right{nullptr}{};
};

typedef struct bTree node;
node* root=nullptr;

void insert(string str)
{
	if(str.length()==0 || str[0]=='N')
		return ;
	vector <string> input;
	istringstream iss(str);
	for(string str;iss>>str;)		input.push_back(str);

	int i=0;
	root=new bTree(stoi(input[i++]));
	queue<node* > q;
	q.push(root);

	while(!q.empty() && i<input.size())
	{
		node* temp=q.front();
		q.pop();
		if(input[i]!="N")
		{
			temp->left=new bTree(stoi(input[i]));
			q.push(temp->left);
		}
		i++;
		if(i>= input.size())		break;
		if(input[i]!="N")
		{
			temp->right=new bTree(stoi(input[i]));
			q.push(temp->right);
		}
		i++;
	}
	
}

void inorder(node* root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int maxWidth()
{
	int max=0;
	if(!root )
		return 0;
	stack<node *>cLevel;
	stack<node *>nLevel;
	
	cLevel.push(root);
	max=cLevel.size();
	while(!cLevel.empty())
	{
		node* temp=cLevel.top();
		cLevel.pop();
		if(temp)
		{
			if(temp->left)	nLevel.push(temp->left);
			if(temp->right)	nLevel.push(temp->right);
		}
		if(cLevel.empty())
		{
			if(max < nLevel.size())		max=nLevel.size();
			swap(cLevel,nLevel);
		}
	}
	return max;
}

int main()
{
	int t;
	cin>>t;
	getchar();
	while(t--)
	{
		string str;
		getline(cin,str);
		insert(str);
		// inorder(root);
		cout<<maxWidth()<<endl;
		root=NULL;
	}
	return 0;
}