

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int r,c;
	cin>>r>>c;
	int a[r][c];
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cin>>a[i][j];
	}
	int n;
	cin>>n;
	int rw[r]={0},cw[c]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			rw[i]+=a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cw[i]+=a[j][i];
		}
	}
	for(int i=0;i<r;i++)
	{
		if(rw[i]==0 && cw[i]==n-1)
		{
			cout<<"Celebrity ID "<<i;
			return 0;
		}
		//cout<<rw[i]<<" "<<cw[i]<<endl;
	}
	cout<<"No Celebrity";
}