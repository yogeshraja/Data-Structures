#include <bits/stdc++.h>
using namespace std;

int seperate(int gila[], int sum, int iterator, int n)
{
    if (sum == 0)
    {
        return 1;
    }
    if (sum < 0)
    {
        return 0;
    }
    if (iterator == n)
        return 0;
    else
    {
        return (seperate(gila, sum - gila[iterator], iterator + 1, n) || seperate(gila, sum, iterator + 1, n));
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, mila;
        cin >> n >> mila;
        int gila[n], gilaSum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> gila[i];
            gilaSum += gila[i];
        }
        if ((gilaSum - mila) % 2 == 1 || mila > gilaSum)
        {
            cout << "0\n";
        }
        else
        {
            cout << seperate(gila, (gilaSum - mila) / 2, 0, n) << endl;
        }
    }
    return 0;
}