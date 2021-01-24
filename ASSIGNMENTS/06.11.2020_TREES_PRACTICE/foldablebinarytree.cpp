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

bool isSame(Node *l, Node *r)
{
    if (!l && !r)
        return true;
    return (l && r) && isSame(l->right, r->left) && isSame(l->left, r->right);
}
bool IsFoldable(Node *root)
{
    if (!root)
        return true;
    return isSame(root->left, root->right);
}

int main()
{
    string treeString;
    getline(cin, treeString);
    Node *root = buildTree(treeString);
    if (IsFoldable(root))
    {
        cout << "Yes\n";
    }
    else
    {
       cout << "No\n";
    }
    return 0;
} 