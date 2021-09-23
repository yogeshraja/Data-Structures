#include <bits/stdc++.h>
using namespace std;

int minDiff(vector<int>arr)
{

    vector<int> out(arr.size());
    int sum = 0;
    sort(arr.begin(), arr.end());
    transform(arr.begin(), arr.end()-1, arr.begin()+1, out.begin(), [](int a, int b)
              { return abs(a - b); });
    sum = accumulate(out.begin(), out.end(), 0);
    return sum;
}

int main()
{
    vector<int> vec = {1, 3, 3, 2, 4};
    cout << minDiff(vec);
}