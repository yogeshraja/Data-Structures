#include<bits/stdc++.h>
using namespace std;

int get(map<int,int> mp,int key)
{
	if(mp.find(key)==mp.end())
		return -1;
	return mp[key];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int size,recent;
		cin>>size;
		map<int,int > mp;
		vector<int >vec;
		int qry;
		cin>>qry;
		while(qry--)
		{
			string s;
			cin>>s;
			if(s=="SET")
			{
				int key,val;
				cin>>key>>val;
				if(mp.find(key)==mp.end())
				{
					if(mp.size()>=size)
					{
						mp.erase(vec[0]);
						vec.erase(vec.begin());
					}
				}
				mp[key]=val;
				auto it=vec.begin();
				it=find(vec.begin(),vec.end(),key);
				if(it!=vec.end())
					vec.erase(it);
				vec.push_back(key);
				
			}
			else if(s=="GET")
			{
				int key;
				cin>>key;
				cout<<get(mp,key)<<" ";
			}

		}
		cout<<endl;
	}
}