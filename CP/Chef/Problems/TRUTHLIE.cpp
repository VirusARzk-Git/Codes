#include <bits/stdc++.h>
using namespace std;
void code()
{
    int n, m;
    cin >> n >> m;
    if (m >= n)
        cout << -1 << endl;
    else
        cout << m + m + 1 << endl;
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
        code();
    return 0;
}