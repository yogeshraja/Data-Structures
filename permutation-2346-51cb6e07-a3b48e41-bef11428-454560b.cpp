#include <bits/stdc++.h>
using namespace std;

string permutations(string s,int i,int x,string permu)
{
	int n=s.size();
	if(x==n)
		return permu;
	if(x==i)
	{
		return permutations(s,i,x+1,permu);
	}
	int j=x;
	permu+=s[i];
	do
	{
		if(j>n-1)
		{
			j=0;
			continue;
		}
		if(j==i)
		{
			j++;
			continue;
		}
		permu+=s[j++];
		// cout<<j<<" "<<x<<endl;
	}while(j!=x);
	// cout<<"-------------------------\n";
	return permutations(s,i,x+1,(permu+" "));
}

void getPermutation(string s)
{
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		cout<<permutations(s,i,0,"");
	}
}

int main() {
	string s;
	cin>>s;
	getPermutation(s);	
}
