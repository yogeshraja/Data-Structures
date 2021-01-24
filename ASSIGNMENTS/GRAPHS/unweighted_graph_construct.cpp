/**
 * @file graph_construct.cpp
 * @author rajayogesh
 * @brief a simple implementation of the Graph DS 
 * @version 0.1
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
#include"graph_traversals.h"
using namespace std;

//structure to represent each vertices

struct Graph
{
    int data;
    vector<struct Graph *> edge; //list to sore the edges of the vertex
    Graph(int d) : data{d} {};
};

typedef struct Graph vertex;
map<int, vertex *> monitor;       //map to store the adjacency graph
map<int, vector<int>> graph_impl; //map to store the adjacency list
vertex *start = NULL;

void printAdjMat()
{
    int n = graph_impl.size();
    int adj_mat[n + 1][n + 1];
    memset(adj_mat, 0, (n + 1) * (n + 1) * sizeof(int));
    int i = 1;
    map<int, int> mp;
    for (auto x : graph_impl)
    {
        adj_mat[0][i] = adj_mat[i][0] = x.first;
        mp[x.first] = i;
        i++;
    }
    i = 1;
    for (auto x : graph_impl)
    {
        int j = 1;
        for (auto y : x.second)
        {
            adj_mat[i][mp[y]] = 1;
            j++;
        }
        i++;
    }
    cout << "----------------------------------  ADJACENCY MATRIX  ----------------------------------" << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * @brief a program that uses the principal of BFS on graphs to print all the elements in the graph that are accessible directly
 * or indirectly from the given vertex.
 * @param stVer indicates the start vertex of the graph
 */
void displayGraph(vertex *stVer)
{
    cout << "----------------------------------  ADJACENCY LIST  ----------------------------------\n"
         << endl;
    stack<vertex *> st;
    st.push(stVer);
    vector<vertex *> vec;
    while (!st.empty())
    {
        vertex *temp = st.top();
        st.pop();
        if (find(vec.begin(), vec.end(), temp) == vec.end())
        {
            cout << temp->data << " ";
            vec.push_back(temp);
        }
        for (auto i : temp->edge)
        {
            if (find(vec.begin(), vec.end(), i) == vec.end())
                st.push(i);
        }
    }
    cout << endl;
}

/**
 * @brief 
 * a function to print the adjacency list.
 * @param graph stores the map containing the adjacency list
 */
void displayAdjList(map<int, vector<int>> graph)
{
    cout << "----------------------------------  ADJACENCY LIST  ----------------------------------\n"
         << endl;
    for (auto i = graph.begin(); i != graph.end(); i++)
    {
        cout << i->first << " ";
        for (auto j : i->second)
        {
            cout << " --> " << j;
        }
        cout << endl;
    }
}

/**
 * @brief 
 * a function to print the adjacency list.
 * @param graph stores the map containing the graph itself
 */
void displayAdjList(map<int, vertex *> graph)
{
    cout << "----------------------------------  ADJACENCY MAP  ----------------------------------\n"
         << endl;
    for (auto i = graph.begin(); i != graph.end(); i++)
    {
        cout << i->first << " ";
        for (auto j = i->second->edge.begin(); j != i->second->edge.end(); j++)
        {
            cout << " --> " << (*j)->data;
        }
        cout << endl;
    }
}

/**
 * @brief function to insert the vertices to the graph
 * 
 * @param d 
 * @param s 
 */
void insert(int d, int s)
{
    vertex *temp = NULL;
    if (start == NULL)
    {
        start = new Graph(d);
        monitor[d] = start;
    }
    else if (monitor.find(d) == monitor.end())
        monitor[d] = new Graph(d);
    temp = monitor[d];
    if (monitor.find(s) == monitor.end())
    {
        monitor[s] = new Graph(s);
    }
    if (find(temp->edge.begin(), temp->edge.end(), monitor[s]) == temp->edge.end())
    {
        temp->edge.push_back(monitor[s]);
    }
}

int main()
{
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
            insert(v, stoi(str));
            graph_impl[v].push_back(stoi(str));
        }
    }
    cout << "\nDisplaying the data stored in the Graph\n";
    displayGraph(start);
    cout << "\nDisplaying the data stored in the adjacency list\n";
    displayAdjList(graph_impl);
    cout << "\nDisplaying the data stored in the Graph Map\n";
    displayAdjList(monitor);
    cout << "\nDisplaying the Adjacency Matrix of the Graph\n";
    printAdjMat();
    for(auto i:graphBFS<vertex*>(start))
    {
        cout << i->data << endl;
    }
    for(auto i:graphDFS<vertex*>(start))
    {
        cout << i->data << endl;
    }
}
/**
5
1
2 3
2
3 4
3
4 5
4
5 1
5
1 2
 */