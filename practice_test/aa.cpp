#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N")
        {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N")
        {

            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int maxPathSum(Node *);

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        cout << maxPathSum(root) << "\n";
    }
    return 0;
} // } Driver Code Ends

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
// int pathFind(Node *root,int mx)
// {
//   if(!root)    return 0;
//   int x=maxPath(root->left)+maxPath(root->right)+root->data;
//   pathFind(root->left,x);
//   pathFind(root->right,x);
//   return mx<x?x:mx;
// }
int maxPath(Node *root)
{
    // if(root->left && root->right)
    //{
    if (!root)
        return 0;
    return (root->data + max(maxPath(root->left), maxPath(root->right)));
    // }
    //return INT_MIN;
}
int maxPathSum(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int max = INT_MIN;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (!(temp->left && temp->right))
            continue;
        if (!temp->right && !temp->left)
            continue;
        int sum = maxPath(temp->left) + maxPath(temp->right) + temp->data;
        max = max < sum ? sum : max;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return max;
}
