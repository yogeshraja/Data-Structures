/**
 * @file roottoleafpaths.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-11-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
#include<cstdio>
#include<complex.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void pathCounts( Node* node);

int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

     pathCounts(root);
     cout<< endl;
  }
  return 0;
}

void count(Node* root,map<int,int> &mp,int pathLen)
{
    if(!root)   return ;
    if(!root->right && !root->left)
    {
        mp[pathLen]++;
        return ;
    }
    count(root->left,mp,pathLen+1);
    count(root->right,mp,pathLen+1);
}
void pathCounts(Node *root)
{
    map<int,int> mp;
    count(root,mp,1);
    for(auto i=mp.begin();i!=mp.end();i++)
        cout<<i->first<<" "<<i->second<<" $";
}