#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
signed main()
{
    int t, ans = 1;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        ans = (ans * (b + 1)) % mod;
    }
    cout << ans << endl;
    return 0;
}