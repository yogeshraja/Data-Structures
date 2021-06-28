/**
 * @file graph_implementation.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-11-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
#include "graph_traversals.h"
using namespace std;

//structure to represent each vertices

struct Graph
{
    int data, weight;
    vector<pair<struct Graph *, int>> edge; //list to sore the edges of the vertex
    Graph(int d) : data{d}, weight{INT_MAX} {};
};

typedef struct Graph vertex;
map<int, vertex *> monitor;                  //map to store the adjacency graph
map<int, vector<pair<int, int>>> graph_impl; //map to store the adjacency list
map<int, vector<pair<int, int>>> adj_impl;   //map to store the generated adjacency list
vertex *start = NULL;

void printAdjMat(map<int, vector<pair<int, int>>> gp_impl)
{
    int n = gp_impl.size();
    int adj_mat[n + 1][n + 1];
    memset(adj_mat, 0, (n + 1) * (n + 1) * sizeof(int));
    int i = 1;
    map<int, int> mp;
    for (auto x : gp_impl)
    {
        adj_mat[0][i] = adj_mat[i][0] = x.first;
        mp[x.first] = i;
        i++;
    }
    i = 1;
    for (auto x : gp_impl)
    {
        int j = 1;
        for (auto y : x.second)
        {
            adj_mat[i][mp[y.first]] = y.second;
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
            if (find(vec.begin(), vec.end(), i.first) == vec.end())
                st.push(i.first);
        }
    }
    cout << endl;
}

/**
 * @brief 
 * a function to print the adjacency list.
 * @param graph stores the map containing the adjacency list
 */
void displayAdjList(map<int, vector<pair<int, int>>> graph)
{
    cout << "----------------------------------  ADJACENCY LIST  ----------------------------------\n"
         << endl;
    for (auto i = graph.begin(); i != graph.end(); i++)
    {
        cout << i->first << " ";
        for (auto j : i->second)
        {
            cout << " --> " << j.first;
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
        vector<pair<int, int>> vec;
        cout << i->first << " ";
        for (auto j : i->second->edge)
        {
            pair<int, int> p;
            p.first = j.first->data;
            p.second = j.second;
            cout << " --> " << j.first->data;
            vec.push_back(p);
        }
        adj_impl[i->first] = vec;
        cout << endl;
    }
}

/**
 * @brief function to create a directed graph
 * 
 * @param d from vertex
 * @param s to vertex
 * @param weight cost of traversal
 */
void directedInsert(int d, int s, int weight)
{
    vertex *temp = NULL;
    if (start == NULL)
    {
        start = new Graph(d);
        //start->weight = 0;
        monitor[d] = start;
    }
    else if (monitor.find(d) == monitor.end())
        monitor[d] = new Graph(d);
    temp = monitor[d];
    pair<vertex *, int> p;
    if (monitor.find(s) == monitor.end())
    {
        monitor[s] = new Graph(s);
    }
    p.first = monitor[s];
    p.second = weight;
    if (find(temp->edge.begin(), temp->edge.end(), p) == temp->edge.end())
    {
        temp->edge.push_back(p);
    }
}
/**
 * @brief to create an undirected graph
 * 
 * @param d from vertex 
 * @param s  to vertex
 * @param weight cost of traversal
 */
void undirectedInsert(int d, int s, int weight)
{
    vertex *temp = NULL;
    if (start == NULL)
    {
        start = new Graph(d);
        //start->weight = 0;
        monitor[d] = start;
    }
    else if (monitor.find(d) == monitor.end())
        monitor[d] = new Graph(d);
    temp = monitor[d];
    pair<vertex *, int> p;
    if (monitor.find(s) == monitor.end())
    {
        monitor[s] = new Graph(s);
    }
    p.first = monitor[s];
    p.second = weight;
    if (find(temp->edge.begin(), temp->edge.end(), p) == temp->edge.end())
    {
        temp->edge.push_back(p);
    }
    pair<vertex *, int> e;
    e.first = monitor[d];
    e.second = weight;
    if (find(monitor[s]->edge.begin(), monitor[s]->edge.end(), e) == monitor[s]->edge.end())
    {
        monitor[s]->edge.push_back(e);
    }
}

int getChoice()
{
    cout << "Please select your Graph\n1.)Directed Graph\n2.)Undirected Graph\n";
    int ch;
    cin >> ch;
    return (ch == 1 || ch == 2) ? ch : getChoice();
}
