#include <bits/stdc++.h>
using namespace std;

void init(vector<vector<int>> &table, int n)
{
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(n, 0);
        table[i] = temp;
    }
}

void findMaxInRange(vector<vector<int>> &table, vector<int> a, int n)
{
    int last_max_col = 0;
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        int maxval = table[i][i + 1];
        if (last_max_col >= i)
        {
            flag = false;
            maxval = a[i];
        }
        int j = (flag)?last_max_col:i + 1;
        for (; j < n; j++)
        {
            if (maxval < a[j])
            {
                maxval = a[j];
                last_max_col = j;
            }
            table[i][j] = maxval;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> table(n);
    vector<int> arr(n);
    init(table, n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    findMaxInRange(table, arr, n);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "Maximum value in the range [" << i + 1 << "," << j + 1 << "] is " << table[i][j] << endl;
        }
    }
}

//1 3 5 4 2

//3 5 5 5
//* 5 5 5 5
//* * 5 5 5 
//* * * 4 4