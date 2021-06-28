#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    int a, b;

    A(int x, int y)
    {
        a = x;
        b = y;
    }

    void display()
    {
        cout << a + b;
    }
};

int main()
{
    int x, y;
    cin >> x >> y;
    A a(x, y);
    a.display();
}