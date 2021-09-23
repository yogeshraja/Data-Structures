#include <bits/stdc++.h>
using namespace std;

struct avl
{
    int data, height;
    struct avl *right, *left;
    avl(int d) : data{d}, height{1}, right{nullptr}, left{nullptr} {};
};

typedef struct avl node;

node *insert(node *, int);
int height(node *root)
{
    if (!root)
        return 0;
    return root->height;
}
int detHeight(node *root)
{
    if (!root)
        return 0;
    return 1 + max(detHeight(root->left), detHeight(root->left));
}
int getBal(node *root)
{
    return height(root->left) - height(root->right);
}
void nodeRecovery(node *root, queue<node *> mq)
{
    while (!mq.empty())
    {
        node *mtemp = mq.front();
        mq.pop();
        queue<node *> q;
        q.push(mtemp);
        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();
            if (!temp)
                continue;
            root = insert(root, temp->data);
            if (!temp->left)
                q.push(temp->left);
            if (!temp->right)
                q.push(temp->right);
        }
    }
}
node *rightRotate(node *A)
{
    node *B = A->left;
    queue<node *> NR;
    NR.push(A->right);
    NR.push(B->right);
    B->right = A;
    A->left = NULL;
    nodeRecovery(B, NR);
    A->height = max(height(A->left), height(A->right)) + 1;
    B->height = max(height(B->left), height(B->right)) + 1;
    return B;
}
node *leftRotate(node *A)
{
    node *B = A->right;
    queue<node *> NR;
    NR.push(A->left);
    NR.push(B->left);
    B->left = A;
    A->right = NULL;
    nodeRecovery(B, NR);
    A->height = max(height(A->left), height(A->right)) + 1;
    B->height = max(height(B->left), height(B->right)) + 1;
    return B;
}
node *insert(node *root, int data)
{
    if (!root)
        return (new avl(data));
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
    {
        return NULL;
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int bal = getBal(root);
    // condition for LL
    if (bal > 1 && data < root->left->data)
        return rightRotate(root);
    // condition for RR
    if (bal < -1 && data > root->right->data)
        return leftRotate(root);
    // condition for LR
    if (bal > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // condition for RL
    if (bal < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // root->height = detHeight(root);
    return root;
}

void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    node *root = NULL;
    int n = 5;
    //int a[] = {1, 2, 3, 4, 5};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
}