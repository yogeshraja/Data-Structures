#include<bits/stdc++.h>
using namespace std;

string longestEvenWord(string sentence){
    string out="";
    stringstream ss(sentence);
    for (string str; ss >> str;){
        if (str.length() % 2 == 0 && str.length() > out.length())
        {
            out = str;
        }
    }
    return out;
}

int main(){

    cout<<longestEvenWord("Hii this is a testy  case");
    return 0;
}