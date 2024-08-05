#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define all(x) x.begin(), x.end()

void code()
{
    int n;
    cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].second >> v[i].first;
    int ans = 0, currEnd = -1;
    sort(all(v));
    for (int i = 0; i < n; i++)
    {
        if (v[i].second >= currEnd)
        {
            ans++;
            currEnd = v[i].first;
        }
    }
    cout << ans;
}

signed main()
{
    code();
    return 0;
}