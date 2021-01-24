#include <bits/stdc++.h>
using namespace std;

int TABLE_SIZE = 10;
class HashTable
{
public:
    int size = 0;
    class pair
    {
    public:
        int key, value;
        struct pair *next;
        pair(int k, int v) : key{k}, value{v}, next{nullptr} {};
    };
    typedef struct pair node;

    vector<node *> table;

    int hashFunction(int key)
    {
        return key % TABLE_SIZE;
    }

    HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
            table.push_back(nullptr);
    }

    void insert(int key, int val)
    {
        int index = hashFunction(key);
        node *temp = table[index];
        if (!temp)
        {
            table[index] = new node(key, val);
            size++;
            return;
        }
        while (temp->next)
        {
            if (temp->key == key)
            {
                temp->value = val;
                return;
            }
            temp = temp->next;
        }
        node *newnode = new node(key, val);
        temp = table[index];
        newnode->next = temp;
        table[index] = newnode;
        size++;
    }

    void printTable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << " ---> ";
            node *temp = table[i];
            while (temp)
            {
                cout << "(" << temp->key << "," << temp->value << ")   ";
                temp = temp->next;
            }

            cout << endl;
        }
    }
};

int main()
{
    HashTable Hash;
    int n;
    cin >> n;
    while (n--)
    {
        int key, val;
        cin >> key >> val;
        Hash.insert(key, val);
    }
    Hash.printTable();
}