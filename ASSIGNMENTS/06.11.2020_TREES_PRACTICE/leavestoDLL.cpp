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

void inOrder(Node *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

Node *convertToDLL(Node *root)
{
    if (!root)
        return NULL;
    Node *head = NULL, *walk;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (!temp->left && !temp->right)
        {
            if (!head)
            {
                head = new Node(temp->data);
                walk = head;
            }
            else
            {
                walk->right = new Node(temp->data);
                walk->right->left = walk;
                walk = walk->right;
            }
            continue;
        }
        if (temp->left)
        {
            q.push(temp->left);
            if (!temp->left->left && !temp->left->right)
            {
                temp->left = NULL;
            }
        }

        if (temp->right)
        {
            q.push(temp->right);
            if (!temp->right->left && !temp->right->right)
            {
                temp->right = NULL;
            }
        }
    }
    return head;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string treeString = "1 2 3 4";
        //getline(cin, treeString);
        Node *root = buildTree(treeString);
        Node *head = convertToDLL(root);
        inOrder(root);
        cout << "\n";
        Node *curr = head, *last = head;
        while (curr)
        {
            cout << curr->data << " ";
            last = curr;
            curr = curr->right;
        }
        cout << "\n";
        curr = last;
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->left;
        }
        cout << "\n";
    }
    return 0;
}
