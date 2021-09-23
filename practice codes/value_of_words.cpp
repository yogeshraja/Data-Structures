#include<bits/stdc++.h>
using namespace std;

int valueOfWord(string str){
    int out = 0;
    int n = str.size();
    if (n % 2 != 0){
        out += str[n / 2] - 'A' + 1;
    }
    for (int i = 0; i < n / 2;i++){
        out+=abs(str[i]-str[n-1-i]);
    }
    return out;
}

int main(){
    string str;
    getline(cin, str);
    stringstream ss(str);
    string out = "";
    for (; ss >> str;)
    {
        out += to_string(valueOfWord(str));
    }
    cout << out;
}