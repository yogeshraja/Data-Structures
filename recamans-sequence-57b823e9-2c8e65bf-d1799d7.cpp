#include <bits/stdc++.h>
using namespace std;

void recamanSequence(int n,int i,int a[])
{
	if(i==n)
		return;
	if(i==1)
		cout<<a[0]<<" ";
	int x=a[i-1]-i;
	for(int j=0;j<i;j++)
	{
		if((a[j]==x) || x<0)
		{
			x=a[i-1]+i;
			break;
		}
	}
	a[i]=x;
	cout<<a[i]<<" ";
	recamanSequence(n,i+1,a);
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		a[0]=0;
		recamanSequence(n,1,a);
		cout<<endl;
	}
}

