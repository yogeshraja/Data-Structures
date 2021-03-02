#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	getline(cin,str);
	int k;
	cin>>k;
	vector<string>vec;
	istringstream iss(str);
	for(string str;iss>>str;) vec.push_back(str);
	map<int,string> mp;
	for(int i=0;i<vec.size();i++)
	{
		string comb="";
		string vals="";
		for(int j=0;j<k;j++,i++)
		{
			comb+=vec[i];
			vals+=" "+vec[i];
		}
		i--;
		mp[stoi(comb)]=vals;
	}
	for(auto i:mp)
	{
		cout<<i.second;
	}
}