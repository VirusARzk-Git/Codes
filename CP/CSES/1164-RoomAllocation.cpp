#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;
using vi = vector<int>;
#define all(x) x.begin(), x.end()
#define debug(x)     \
    for (auto i : x) \
        cout << i << ' ';

void code()
{
    int n;
    cin >> n;
    vector<pair<pii, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({{a, b}, i});
    }
    sort(v.begin(), v.end());
    vi ans(n);
    int rooms = 0;
    priority_queue<pii> pq;
    for (int i = 0; i < n; i++)
    {
        if (pq.empty())
        {
            rooms++;
            pq.push({-v[i].first.second, rooms});
            ans[v[i].second] = rooms;
        }
        else
        {
            pii p = pq.top();
            if (-p.first < v[i].first.first)
            {
                pq.pop();
                pq.push({-v[i].first.second, p.second});
                ans[v[i].second] = p.second;
            }
            else
            {
                rooms++;
                pq.push({-v[i].first.second, rooms});
                ans[v[i].second] = rooms;
            }
        }
    }
    cout << rooms << endl;
    debug(ans);
}

signed main()
{
    code();
    return 0;
}