#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st, vector<vector<int>> &scc, bool store)
{
    visited[node] = true;
    for (int i : adj[node])
        if (!visited[i])
            dfs(i, adj, visited, st, scc, store);
    if (store)
        st.push(node);
    else
        scc.back().push_back(node);
}

int kosaraju(int V, vector<vector<int>> &adj)
{
    stack<int> st;
    vector<vector<int>> scc;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i, adj, visited, st, scc, true);

    vector<vector<int>> adjRev(V);
    for (int i = 0; i < V; i++)
        for (int j : adj[i])
            adjRev[j].push_back(i);

    fill(visited.begin(), visited.end(), false);
    int count = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            scc.push_back({});
            dfs(node, adjRev, visited, st, scc, false);
            count++;
        }
    }
    for (auto i : scc)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return count;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << kosaraju(V, adj);
    return 0;
}