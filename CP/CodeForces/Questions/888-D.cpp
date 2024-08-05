#include <bits/stdc++.h>
using namespace std;
#define int long long

int nCr(int n, int r)
{
    if (r > n || r < 0)
        return 0;
    if (r == 0 || r == n)
        return 1;
    if (r == 1)
        return n;
    if (r > n - r)
        r = n - r;
    int ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}

void code()
{
    int n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << 1 << '\n';
        return;
    }
    int ans = 1;
    vector<int> v = {1, 2, 9};
    for (int i = 2; i <= k; i++)
    {
        int p = v[i - 2];
        ans += nCr(n, i) * p;
    }
    cout << ans << '\n';
}

signed main()
{
    int t = 1;
    // cin>> t;
    while (t--)
        code();
    return 0;
}