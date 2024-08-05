#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

void code()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pii>> adj(n + 1);
    priority_queue<int> best[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    best[1].push(0);
    pq.push({0, 1});
    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > best[u].top())
            continue;
        for (auto &[v, w] : adj[u])
        {
            int dist = d + w;
            if (best[v].size() < k)
            {
                pq.push({dist, v});
                best[v].push(dist);
            }
            else if (best[v].top() > dist)
            {
                best[v].pop();
                best[v].push(dist);
                pq.push({dist, v});
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(best[n].top());
        best[n].pop();
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans)
        cout << i << ' ';
}


signed main()
{
    code();
    return 0;
}