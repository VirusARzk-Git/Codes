// Linear Diophantine Equation

#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, x, y;
        cin >> a >> b;
        int hcf = gcd(a, b, x, y);
        cout << x << ' ' << y << ' ' << hcf << endl;
    }
    return 0;
}
