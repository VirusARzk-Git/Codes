#include <bits/stdc++.h>
using namespace std;
#define int long long
void code()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    int ans = 0, f = 0;
    for (int i = 0; i < n; i++)
    {
        f += v[i].first;
        ans += v[i].second - f;
    }
    cout << ans;
}

signed main()
{
    code();
    return 0;
}