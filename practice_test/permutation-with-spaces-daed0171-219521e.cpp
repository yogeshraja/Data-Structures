#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		reverse(s.begin(),s.end());
		int n=0;
		for(int i=1;i<s.size();i++)
		{
			n=n<<1;
			n=n|1;
		}
		//cout<<n<<"___";
		for(int i=n;i>=0;i--)
		{
			int k=i;
			cout<<"(";
			string str="";
			for(auto j:s)
			{
				str+=j;
				if(k%2)	str+=" ";
				k=k>>1;
			}
			cout<<string(str.rbegin(),str.rend());
			cout<<")";
		}
		cout<<endl;
	}
}