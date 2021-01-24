#include<bits/stdc++.h>
using namespace std;

struct bTree
{
	int data;
	struct bTree *left,*right;
	bTree(int d):data{d},left{nullptr},right{nullptr}{};
};

typedef struct bTree node;
node* root=NULL;
void insert(string str)
{
	if(str.length()==0 || str[0]=='N')
		return ;
	vector<string> input;
	istringstream iss(str);
	for(string str;iss>>str;)
		input.push_back(str);

	root= new bTree(stoi(input[0]));
	queue<node *> q;
	q.push(root);
	int i=1;
	while(!(q.empty()) && i<input.size())
	{
		node *temp=q.front();
		q.pop();
		if(input[i]!="N")
		{
			temp->left=new bTree(stoi(input[i]));
			q.push(temp->left);
		}
		i++;
		if(i>=input.size()) break;
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
		return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void zigzag()
{
	if(!root)
		return ;

	stack <node *> cLevel;
	stack <node *> nLevel;

	bool l2r=true;

	cLevel.push(root);

	while(!cLevel.empty())
	{
		node * temp=cLevel.top();
		cLevel.pop();

		if(temp)
		{
			cout<<temp->data<<" ";
			if(l2r)
			{
				if(temp->left)		nLevel.push(temp->left);
				if(temp->right)		nLevel.push(temp->right);
			}
			else
			{
				if(temp->right)		nLevel.push(temp->right);
				if(temp->left)		nLevel.push(temp->left);
			}
		}
		if(cLevel.empty())
		{
			l2r=!l2r;
			swap(cLevel,nLevel);
		}
	}

}

int main()
{
	int t;
	cin>>t;
	getchar();
	while(t--)
	{
		string s;
		
		getline(cin,s);
		// cout<<s<<"---";
		insert(s);
		// inorder(root);
		zigzag();
		cout<<endl;
		root=NULL;
	}
}