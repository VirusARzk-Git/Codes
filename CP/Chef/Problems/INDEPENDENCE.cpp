#include <bits/stdc++.h>
using namespace std;
#define int long long
void code()
{
    int a, b, c;
    cin >> a >> b >> c;
    int m = max({a, b, c});
    if (m > a + b + c - m + 1)
        cout << "NO\n";
    else
        cout << "YES\n";
}

signed main()
{
    int tc = 1;
    cin >> tc;
    while (tc--)
        code();
    return 0;
}