#include<bits/stdc++.h>
using namespace std;

void displayGraph(map<int,vector<int>> graph,int v)
{
    for (int i = 0; i < v;i++)
    {
        cout << i << " ";
        for (auto j = graph[i].begin(); j != graph[i].end();j++)
        {
            cout << " --> " << *j;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    map<int,vector<int >> graph_impl;
    int i = n;
    while(i--)
    {
        int v;
        cin >> v;
        string s;
        getchar();
        getline(cin, s);
        istringstream iss(s);
        for (string str; iss >> str;)
        {
            graph_impl[v].push_back(stoi(str));
            // graph_impl[stoi(str)].push_back(v);
        }
    }
    displayGraph(graph_impl, n);
}