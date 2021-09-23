#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<char>> vec;
    for(int i=0;i<n;i++){
        vector<char> temp(2*n,' ');
        for(int j=0;j<=i;j++){
            temp[j]='*';
            temp[2 * n - 1 - j] = '*';
        }
        vec.push_back(temp);
    }
    for(auto i:vec){
        copy(i.begin(),i.end(),ostream_iterator<char>(cout," "));
        cout << endl;
    }
    for (auto i = vec.rbegin(); i != vec.rend(); i++)
    {
        copy(i->begin(),i->end(),ostream_iterator<char>(cout," "));
        cout<<endl;
    }
}