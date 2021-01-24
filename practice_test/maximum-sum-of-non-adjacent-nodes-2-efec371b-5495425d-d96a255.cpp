#include <bits/stdc++.h>
using namespace std;

struct bTree
{
	int data;
	struct bTree *left,*right;
	bTree(int d):data{d},left{nullptr},right{nullptr}{};
};

typedef struct bTree node;
node *root=NULL;

int findMax(int a ,int b)
{
	return a>b?a:b;
}

int maxSum(node* root,int sum)
{
	if(!root)		return sum;

	int s1=findMax(maxSum(root->left,sum),maxSum(NULL,sum+root->data));
	int s2=findMax(maxSum(root->right,sum),maxSum(NULL,sum+root->data));

	return s1+s2;
}

void insert(string str)
{
	if(str.length()==0 || str[0]=='N')  return ;
	vector <string> input;
	istringstream iss(str);
	for(string str;iss>>str;)		input.push_back(str);
	int i=1;
	root=new bTree(stoi(input[0]));
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
		if(i >= input.size())		break;
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
	if(!root)		return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
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
		cout<<maxSum(root,0)/2<<endl;
		root=nullptr;
	}
	return 0;
}