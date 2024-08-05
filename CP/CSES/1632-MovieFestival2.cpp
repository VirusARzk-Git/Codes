#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

void code()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<pii> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].second >> v[i].first;
    sort(v.begin(), v.end());
    multiset<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = s.upper_bound(v[i].second);
        if (it != s.begin())
        {
            it--;
            s.erase(it);
            s.insert(v[i].first);
            ans++;
        }
        else if (s.size() < k)
        {
            s.insert(v[i].first);
            ans++;
        }
    }
    cout << ans;
}

signed main()
{
    code();
    return 0;
}