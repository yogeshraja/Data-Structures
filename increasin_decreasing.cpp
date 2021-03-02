#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    map<char, int> mp;
    getline(cin, str);
    int n = str.length();
    for (auto  i :str)
    {
        mp[i]++;
    }
    string result="";
    bool flag = true;
    bool flag1 = false;
    while(flag)
    {
        flag = false;
        string temp = "";
        for (auto i = mp.begin(); i != mp.end();i++)
        {
            if(!i->second)
                continue;
            temp = temp+i->first;
            i->second--;
            flag = true;
        }
        if(flag1)
            reverse(temp.begin(), temp.end());
        flag1 = !flag1;
        result += temp;
    }
    cout << result;
}