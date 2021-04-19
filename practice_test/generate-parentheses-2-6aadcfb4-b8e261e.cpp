#include <bits/stdc++.h>
using namespace std;

void getParanthesis(set<string> &mp, int x, int y, int n, string out)
{
	if (x >= n && y >= n)
	{
		mp.insert(out);
		return;
	}
	if (y > x)
		return;
	if (x > y)
	{
		getParanthesis(mp, x, y + 1, n, out + ")");
	}
	if (x < n)
	{
		getParanthesis(mp, x + 1, y, n, out + "(");
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		set<string> mp;
		getParanthesis(mp, 0, 0, n, "");
		for (auto i : mp)
		{

			cout << i << endl;
		}
	}
}