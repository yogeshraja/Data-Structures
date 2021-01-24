#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)		cin>>a[i];
		int max=0;
		for(int i=0;i<n;i++)
		{
			int vol=0;
			for(int j=i+1;j<n;j++)
			{
				vol=(j-i)*(a[i]<a[j]?a[i]:a[j]);
				max=max>vol?max:vol;
			}
		}
		cout<<max<<endl;
	}
}