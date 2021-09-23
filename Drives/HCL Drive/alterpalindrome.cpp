

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str){
    string temp = str;
    reverse(temp.begin(),temp.end());
    if(str==temp){
        return true;
    }
    return false;
}

string breakPalindrome(string palindromeStr)
{
    bool flag = false;
    for (int i = 0; i < palindromeStr.length(); i++)
    {
        char ch = 'a';
        for (int j = 0; j < 26;j++){
            if (palindromeStr[i] > (ch+j))
            {
                char temp = palindromeStr[i];
                palindromeStr[i] = ch + j;
                if(!isPalindrome(palindromeStr))
                {
                    flag = true;
                    break;
                }
                palindromeStr[i] = temp;
            }
        }
        if(flag)
            break;
    }
    return ((flag) ? palindromeStr : "IMPOSSIBLE");
}

int main()
{
    string str;
    cin >> str;
    cout << breakPalindrome(str);
}