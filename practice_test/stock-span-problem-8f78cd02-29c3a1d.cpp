#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n],span[n];
		for(int i=0;i<n;i++)		cin>>a[i];
		
		for(int i=n-1;i>=0;i--)
		{
			int spn=1,j=i-1;
			while(j>=0)	
			{
				if(a[i]>=a[j--])	spn++;
				else	break;
			}
			span[i]=spn;
		}
		for(int i=0;i<n;i++)		cout<<span[i]<<" ";
		cout<<endl;
	}
}