#include<bits/stdc++.h>
using namespace std;

void findPermu(vector<string > &vec,string input,string out)
{
	if(input.size() <= 0)
	{
		if(find(vec.begin(),vec.end(),out)==vec.end())
			vec.push_back(out);
		return ;
	}
	for(int i=0;i<input.size();i++)
	{
		findPermu(vec,input.substr(1),out+input[0]);
		rotate(input.begin(),input.begin()+1,input.end());
	}
}

int main()
{
	int count=0;
	string text,pat;
	cin>>text>>pat;
	sort(pat.begin(),pat.end());
	vector <string > vec;
	findPermu(vec,pat,"");
	for(auto i:vec)
	{
		size_t found=text.find(i);
		while(found!=string::npos)
		{
			count++;
			found=text.find(i,found+1);
		}
	}
	cout<<count;
}