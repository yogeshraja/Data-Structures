#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    void setVal(int d)
    {
        data = d;
    }
    int getval()
    {
        return data;
    }
    void setNext(Node *nex)
    {
        next = nex;
    }
    Node *getNext()
    {
        return next;
    }

    Node(int d) : data{d}, next{NULL} {};
};

Node *insert(vector<int> vec)
{
    Node *head = NULL;
    Node *curr = NULL;
    for (auto i : vec)
    {
        if (head == NULL)
        {
            head = new Node(i);
            curr = head;
        }
        else{
            curr->setNext(new Node(i));
            curr = curr->getNext();
        }
        
    }
    return head;
}

void cutRotate(Node* head,int k)
{
    Node *curr = head;
    Node *temp = NULL;
    while(curr->getNext())
    {
        for (int i = 0; i < k;i++)
        {

        }
        temp = curr->getNext();
        curr->setNext(curr);
        curr = temp;
    }
    head = curr;
}

int main()
{
    Node *head = nullptr;
    string str = "";
    getline(cin, str);
    int k=0;
    cin >> k;
    stringstream ss(str);
    vector<int> vec;
    try
    {
        while (ss >> str)
        {
            vec.push_back(stoi(str));
        }
    }
    catch (exception e)
    {
        cout << e.what();
    }
    head = insert(vec);
    cutRotate(head,k);
    cout << head->getval();
}