#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int maxi;
int isConnected(int src,int dst,int n)
{
	if(n==0)
		return maxi;
	if(mp[src]==dst)
		return n;
	return isConnected(mp[src],dst,n-1);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		maxi=n;
		mp[1]=1;
		for(int i=1;i<n;i++)
		{
			int x;
			cin>>x;
			mp[i+1]=x;
		}	
			
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				int allow = n-isConnected(i,j,n-1);
				if(allow)
					cout<<i<<" "<<j<<" "<<allow<<" ";
			}
		}
		cout<<endl;
	}
}