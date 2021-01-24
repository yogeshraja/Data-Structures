#include <bits/stdc++.h>
using namespace std;

struct BinTree
{
	string data;
	struct BinTree *left, *right;
	BinTree(string d) : data{d}, left{nullptr}, right{nullptr} {};
};

typedef struct BinTree node;
node *root = NULL;

void insert(string data)
{
	if (root == NULL)
	{
		root = new BinTree(data);
	}
	else
	{
		node *temp;
		queue<node *> q;
		q.push(root);
		while (!q.empty())
		{
			temp = q.front();
			q.pop();
			if (temp->left == NULL)
			{
				temp->left = new BinTree(data);
				break;
			}
			else
			{
				q.push(temp->left);
			}
			if (temp->right == NULL)
			{
				temp->right = new BinTree(data);
				break;
			}
			else
			{
				q.push(temp->right);
			}
		}
	}
}
void inorder(node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->data;
		inorder(root->right);
	}
}
int postOrder(node *root)
{
	cout << "hii" << endl;
	if (root != NULL)
	{
		if (root->left == NULL || root->right == NULL)
		{
			stringstream str(root->data);
			int m;
			str >> m;
			return m;
		}

		int d1 = postOrder(root->left);
		int d2 = postOrder(root->right);
		if (root->data == "+")
			return d1 + d2;
		if (root->data == "-")
			return d1 - d2;
		if (root->data == "*")
			return d1 * d2;
		if (root->data == "/")
			return d1 / d2;
	}
	return 0;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string x;
			cin >> x;
			insert(x);
		}
		cout << postOrder(root) << endl;
		root = NULL;
	}
}