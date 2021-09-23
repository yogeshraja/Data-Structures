#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vec.push_back(x);
    }
    cin >> x >> y;
    reverse(vec.begin() + x, vec.begin() + y + 1);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
}