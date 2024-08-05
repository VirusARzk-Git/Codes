
#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define all(x) x.begin(), x.end()
#define testcase_chalao_bhai \
    ll virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)

bool myCmp(pair<ll, ll> p1, pair<ll, ll> p2)
{
    if (p1.first < p2.first)
        return false;
    else if (p1.first > p2.first)
        return true;
    return (p1.second < p2.second);
}

void func()
{
    ll n, m, h;
    cin >> n >> m >> h;
    vector<vector<ll>> v;
    for (ll idx1 = 0; idx1 < n; idx1++)
    {
        vector<ll> t;
        for (ll idx2 = 0; idx2 < m; idx2++)
        {
            ll tm;
            cin >> tm;
            t.push_back(tm);
        }
        sort(all(t));
        v.push_back(t);
    }

    vector<pair<ll, ll>> vv;
    for (ll idx1 = 0; idx1 < n; idx1++)
    {
        ll penalty = 0, pts = 0, elapsed = 0;
        for (ll idx2 = 0; idx2 < m; idx2++)
        {
            if (v[idx1][idx2] <= (h - elapsed))
                elapsed += v[idx1][idx2], penalty += elapsed, pts++;
            else
                break;
        }
        vv.push_back({pts, penalty});
    }
    ll pts = vv[0].first;
    ll penalty = vv[0].second;
    sort(all(vv), myCmp);
    for (ll idx1 = 0; idx1 < vv.size(); idx1++)
    {
        pair<ll, ll> it = vv[idx1];
        if (it.first == pts && it.second == penalty)
        {
            cout << idx1 + 1 << endl;
            return;
        }
    }
}

signed main()
{
    testcase_chalao_bhai
    func();
    return 0;
}