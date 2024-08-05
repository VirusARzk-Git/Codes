#include <bits/stdc++.h>
using namespace std;

#define int long long

void code()
{
    int q, s, a, b;
    cin >> q >> s >> a >> b;
    int mod = (1ll << 32), ans = 0;
    bitset<2000000005> bs;
    while (q--)
    {
        int x = s / 2;
        if (s % 2 == 0)
        {
            if (bs[x] == 1)
                bs[x] = 0, ans -= x;
        }
        else if (bs[x] == 0)
            bs[x] = 1, ans += x;
        s = (a * s + b) % mod;
    }
    cout << ans;
}

signed main()
{
    code();
    return 0;
}