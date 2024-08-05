#include <bits/stdc++.h>
using namespace std;

void code()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (i * max(n - i, 1));
    cout << ans << endl;
}

signed main()
{
    code();
    return 0;
}