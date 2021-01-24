#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,temp;
		cin>>n;
		temp=n;
		for(int i=0;i<n;i++)	cin>>x;
		x=0;
		while(n>0)
		{
			n=temp;
			n-=pow(2,++x);
		}
		cout<<x<<endl;
	}
}