#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    int ans = 0, sum = 0;
    map<int, int> m;
    m[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        ans += m[sum - x];
        m[sum]++;
    }
    cout << ans;
}

signed main()
{
    solve();
    return 0;
}
