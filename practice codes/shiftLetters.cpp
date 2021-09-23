#include <bits/stdc++.h>
using namespace std;

// string shiftingLetters(string s, vector<int> &shifts)
// {
//     int sum = accumulate(shifts.begin(), shifts.end(), 0);
//     for (int i = 0; i < shifts.size(); i++)
//     {
//         s[i] += sum % 26;
//         if(s[i]>'z'){
//             s[i] = 'a' + (s[i] % 'z');
//         }
//         sum -= shifts[i];
//     }
//     return s;
// }

string shiftingLetters(string s, vector<int> &shifts)
{
    for (int i = 0; i < shifts.size(); i++)
    {
        for (int j = 0; j <= i;j++){
            cout << (shifts[i] + s[j])%'z'<<endl;
            s[j] += shifts[i];
            if(s[j]>'z'){
                s[j] = s[j] % 'z' + 'a' - 1;
            }
        }
    }
    return s;
}

int main(int argc, char **argv)
{
    string str;
    cin >> str;
    vector<int> shifts = {26,9,17};
    cout << shiftingLetters(str, shifts);
}