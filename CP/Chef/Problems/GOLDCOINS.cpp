#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (x > y)
        cout << a;
    else
        cout << b;
    return 0;
}