#include <bits/stdc++.h>
#include "Graph_includes/Graph.h"
using namespace std;

map<vertex *, vertex *> kruskalsMST(map<int, vertex *> gp)
{
    map<vertex *, vertex *> mp;
    for (auto i = gp.begin(); i != gp.end(); i++)
    {
        for (auto j = i->second->edge.begin(); j != i->second->edge.end(); j++)
        {
            if (j->first->weight > (j->second))
            {
                j->first->weight = j->second;
                mp[j->first] = i->second;
            }
        }
    }
    return mp;
}

int main()
{
    int ch = getChoice();
    int n; //number of vertices
    cin >> n;
    int i = n;
    while (i--)
    {
        int v;
        cin >> v; //vertex
        string s;
        getchar();
        getline(cin, s); //edges
        istringstream iss(s);
        for (string str; iss >> str;)
        {
            int n = stoi(str);
            iss >> str;
            int weight = stoi(str);
            if (ch == 1)
                directedInsert(v, n, weight);
            else
                undirectedInsert(v, n, weight);
            pair<int, int> p;
            p.first = n;
            p.second = weight;
            graph_impl[v].push_back(p);
        }
    }
    cout << "\nDisplaying the data stored in the Graph\n";
    displayGraph(start);
    cout << "\nDisplaying the data stored in the adjacency list\n";
    displayAdjList(graph_impl);
    cout << "\nDisplaying the data stored in the Graph Map\n";
    displayAdjList(monitor);
    cout << "\nDisplaying the Adjacency Matrix of the Graph\n";
    printAdjMat(adj_impl);
    for (auto i : graphDFS<vertex *>(start))
        cout << i->data << " ";
    cout << endl;
    for (auto i : graphBFS<vertex *>(start))
        cout << i->data << " ";
    cout << endl;
    for (auto i : kruskalsMST(monitor))
    {
        cout << i.second->data << " ---> " << i.first->data << endl;
    }
}
/**
5
1
2 1 3 2
2
3 5 4 6
3
4 2 5 3
4
5 2 1 4
5
1 2 2 3
 */

/*
5
3
1 4 5 3
1
5 2 2 5 4 6
5
4 1 6 4
4
2 2 6 2
2
6 3
*/