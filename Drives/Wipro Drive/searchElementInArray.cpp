#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, src;
    cin >> n >> src;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    cout << find(vec.begin(), vec.end(), src) - vec.begin();
}