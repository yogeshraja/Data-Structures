#include <bits/stdc++.h>
using namespace std;
bool compare(string &s1,string &s2)
{
	return s1.size()<s2.size();
}
int main()
{
	string str;
	map<string,string> mp;
	getline(cin, str);
	int n=str.length();
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			string sub1=str.substr(i,j);
			string sub2=sub1;
			// cout<<sub1<<endl;
			reverse(sub2.begin(),sub2.end());
			if(sub2==sub1)
			{
				mp[sub2]=sub1;
			}
		}
	}
	vector<string> result;
	for(auto i:mp)
	{
		result.push_back(i.first);
	}
	sort(result.begin(),result.end(),compare);
	for(auto i:result)
	{
		cout<<i<<" ";
	}
}