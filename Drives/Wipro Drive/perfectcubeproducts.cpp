#include <bits/stdc++.h>
using namespace std;

bool isPerfectCube(long n, long &crt)
{
    crt = pow(n, 1.0 / 3.0);
    if (crt * crt * crt == n)
    {
        return true;
    }
    return false;
}

long findBalance(long n, long crt)
{
    long val = pow(crt + 1, 3);
    return val - n;
}

int main()
{
    long n, sum=0, crt;
    cin >> n;
    for (long i = 0; i < n; i++)
    {
        long x;
        cin >> x;
        sum += x;
    }
    if (isPerfectCube(sum, crt))
    {
        cout<<"Yes";
        return 0;
    }
    int x=findBalance(sum, crt);
    if(x){
        cout << x;
    }
    else{
        cout << "Yes";
    }
}