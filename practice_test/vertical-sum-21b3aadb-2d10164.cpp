#include<bits/stdc++.h>
using namespace std;

struct btree
{
	int data;
	struct btree *left,*right;
	btree(int d):data{d},left{nullptr},right{nullptr}{};
};

typedef struct btree node;
node* root=NULL;

void insert(string str)
{
	if(str[0]=='N' || str.length()==0)	return ;
	istringstream iss(str);
	int i=1;
	vector<string > vs;
	for(string str;iss>>str;)		
		vs.push_back(str);
	root=new btree(stoi(vs[0]));
	queue<node*>q;
	q.push(root);
	while(!q.empty() && i<vs.size())
	{
		node* temp=q.front();
		q.pop();
		if(vs[i]!="N")
		{
			temp->left=new btree(stoi(vs[i]));
			q.push(temp->left);
		}
		i++;
		if(i>=vs.size())	break;
		if(vs[i]!="N")
		{
			temp->right=new btree(stoi(vs[i]));
			q.push(temp->right);
		}
		i++;
	}
}

void vSumleftright(node* root,int i,map<int,int > &mp)
{
	if(!root)	return ;
	mp[i]+=root->data;
	vSumleftright(root->right,i+1,mp); 
	vSumleftright(root->left,i-1,mp); 
}

void vSum(node* root)
{
	map <int,int> mp;
	vSumleftright(root,0,mp);
	// cout<<mp.size();
	for(auto i=mp.begin();i!=mp.end();i++)
		cout<<i->second<<" ";
}

void inorder(node* root)
{
	if(!root)	return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}
int  main()
{
	int t;
	cin>>t;
	getchar();
	while(t--)
	{
		string str;
		getline(cin,str);
		// cout<<str;
		insert(str);
		//inorder(root);
		vSum(root);
		cout<<endl;
		root=NULL;
	}
}