#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N], parent(N, -1), dist(N, 0), inDegree(N, 0);
vector<bool> vis(N, false);

void dfs(int u, int p)
{
    vis[u] = true;
    for (int v : adj[u])
        if (v != p && !vis[v])
            dfs(v, u);
}

void code()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        inDegree[b]++;
    }
    dfs(1, -1);
    if (!vis[n])
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0)
            q.push(i);

    fill(dist.begin(), dist.end(), -1e9);
    dist[1] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] < dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }
    vector<int> path;
    for (int u = n; u != 1; u = parent[u])
        path.push_back(u);
    path.push_back(1);
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for (int i : path)
        cout << i << ' ';
}

signed main()
{
    code();
    return 0;
}