#include<bits/stdc++.h>
using namespace std;
struct BinTree
{
    string data;
    struct BinTree *left,*right;
    BinTree(string d) : data{d}, left{nullptr}, right{nullptr}{};
};
typedef struct BinTree node;
node* root=NULL;

void insert(string data)
{
    if(root==NULL)
    {
        root=new BinTree(data);
    }
    else
    {
        node *temp;
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            if(temp->left==NULL)
            {
                temp->left=new BinTree(data);
                break;
            }
            else
                q.push(root->left);
            if(temp->right==NULL)
            {
                temp->right=new BinTree(data);
                break;
            }
            else
                q.push(root->right);
        }
    }
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        while (n--)
        {
            string x;
            cin>>x;
            insert(x);
        }
        inorder(root);
    }
}