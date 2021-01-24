#include <bits/stdc++.h>
using namespace std;

template <typename t>
vector<t> graphDFS(t stVer)
{
    cout << "----------------------------------  DFS ON GRAPH  ----------------------------------\n"
         << endl;
    stack<t> st;
    st.push(stVer);
    vector<t> vec;
    while (!st.empty())
    {
        t temp = st.top();
        st.pop();
        if (find(vec.begin(), vec.end(), temp) == vec.end())
        {
            vec.push_back(temp);
        }
        for (auto i : temp->edge)
        {
            if (find(vec.begin(), vec.end(), i.first) == vec.end())
                st.push(i.first);
        }
    }
    return vec;
}
template <typename t>
vector<t> graphBFS(t stVer)
{
    cout << "----------------------------------  BFS ON GRAPH  ----------------------------------\n"
         << endl;
    queue <t> q;
    q.push(stVer);
    vector<t> vec;
    while (!q.empty())
    {
        t temp = q.front();
        for (auto i : temp->edge)
        {
            if (find(vec.begin(), vec.end(), i.first) == vec.end())
            {
                q.push(i.first);
                vec.push_back(i.first);
            }
        }
        q.pop();
    }
    return vec;
}