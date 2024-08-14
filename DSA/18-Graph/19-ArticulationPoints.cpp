#include <bits/stdc++.h>
using namespace std;

vector<int> tin, low;
vector<vector<int>> g;
vector<bool> mark;
int time = 0;
void dfs(int curr, int par = -1)
{
    int child = 0;
    tin[curr] = low[curr] = time++;
    for (int next : g[curr])
    {
        if (next == par)
            continue;
        if (tin[next] == -1)
        {
            dfs(next, curr);
            low[curr] = min(low[curr], low[next]);
            if (low[next] >= tin[curr] && par != -1)
                mark[curr] = true;
            child++;
        }
        else
            low[curr] = min(low[curr], tin[next]);
    }
    if (par == -1 && child > 1)
        mark[curr] = true;
}

vector<int> articulationPoints(int V, vector<int> adj[])
{
    vector<int> ans;
    tin.assign(V, -1);
    low.assign(V, -1);
    for (int i = 0; i < V; i++)
        g.push_back(adj[i]);
    mark.assign(V, false);
    dfs(0);
    for (int i = 0; i < V; i++)
        if (mark[i])
            ans.push_back(i);
    if (ans.empty())
        ans.push_back(-1);
    return ans;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = articulationPoints(V, adj);
    for (int ele : ans)
        cout << ele << " ";
    return 0;
}