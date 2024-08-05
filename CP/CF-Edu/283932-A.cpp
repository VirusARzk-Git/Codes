#include <bits/stdc++.h>
using namespace std;

#define int long long unsigned

bool good(int m, int w, int h, int n)
{
    int a = m / w, b = m / h;
    return (a * b >= n);
}

void code()
{
    int w, h, n;
    cin >> w >> h >> n;
    int l = max(w, h), r = 1e18;
    int ans = ULLONG_MAX;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (good(m, w, h, n))
            ans = m, r = m - 1;
        else
            l = m + 1;
    }
    cout << ans << endl;
}

signed main()
{
    code();
    return 0;
}