#include <bits/stdc++.h>
using namespace std;

#define int long long unsigned

using vi = vector<int>;
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

void code()
{
    int n, k;
    cin >> n >> k;
    vi v(k);
    for (int i = 0; i < k; i++)
        cin >> v[i];
    int m = 1 << k;
    int ans = 0;
    for (int i = 1; i < m; i++)
    {
        int p = 1;
        for (int j = 0; j < k; j++)
        {
            if ((1 << j) & i)
                if (p <= ULLONG_MAX / v[j])
                    p = (p * v[j] * 1ull);
                else
                {
                    p = ULLONG_MAX;
                    break;
                }
        }
        int b = __builtin_popcount(i);
        if (p <= n)
            if (b % 2)
                ans += n / p;
            else
                ans -= n / p;
    }
    cout << ans;
}

signed main()
{
    noTLE;
    code();
    return 0;
}