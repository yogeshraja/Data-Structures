#include<bits/stdc++.h>
using namespace std;

bool additive(string a, int last, int current,int last2)
{
    int len = a.size();
    if(len==0 && current==3)
        return true;
    if(len==0)
        return false;
    bool op = false;
    if(current==1)
    {
        for(int i=1;i<a.size();i++)
        {
            stringstream s(a.substr(0,i));
            int n;
            s>>n;
            op = op || additive(a.substr(i,len-i),n,2,last2);
        }
        return op;
    }
    if(current==2)
    {
        bool op= false;
        for(int i=1;i<a.size();i++)
        {
            stringstream s(a.substr(0,i));
            int n;
            s>>n;
            int temp = last + n;
            op = op || additive(a.substr(i,len-i),temp,3,n);
        }
        return op;
    }
    if(current==3)
    {
        bool op = false;
        for(int i=1;i<=a.size();i++)
        {
            stringstream s(a.substr(0,i));
            int n;
            s>>n;
            if(n==last)
            {
                int temp = last2 + n;
                op = op || additive(a.substr(i,len-i),temp,3,n);
            }
        }
        return op;
    }
}
bool isAdditiveSequence(string n)
{
    return additive(n,0,1,0);
}
int main()
{
    string s="1235813";
    cout << isAdditiveSequence(s) << endl;
}