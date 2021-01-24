#include<bits/stdc++.h>
using namespace std;


void rotate(vector<vector<int>> &a,int n)
{
	vector<vector<int>> rot=a;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=rot[j][i];
		}
	}
}

string lefttoright(vector<vector<int>> a,int n)
{
	string s="";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==1)
			{
				s+=to_string(j+1);
			}
		}
	}
	return s;
}

void printpossible(vector<vector<int>> a,int n)
{
	vector<string> vs;
	string s;
	for(int i=0;i<4;i++)
	{
		s=lefttoright(a,n);
		rotate(a,n);
		if(find(vs.begin(),vs.end(),s)==vs.end())	
		{
			vs.push_back(s);
			cout<<"["<<s<<"]";
		}
	}
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n==2 || n==3 || n==9)
		{
			cout<<"-1"<<endl;
			continue;
		}
		vector<vector<int>>a(n);
		for(int i=0;i<n;i++)
		{
			a[i]=vector<int>(n);
			for(int j=0;j<n;j++)
			{
				a[i][j]=0;
			}
		}
		int temp=n;
		int x=-1,y=-1;
		while(temp--)
		{
			x++;
			y+=2;
			if(y>n-1)
			{
				y%=n;
				if(n%2==0)
					y--;
			}
			a[x][y]=1;
		}
		// for(int i=0;i<n;i++)
		// {
		// 	for(int j=0;j<n;j++)
		// 	{
		// 		cout<<a[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		printpossible(a,n);
		cout<<endl;
	}
}