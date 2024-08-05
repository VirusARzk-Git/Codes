#include <bits/stdc++.h>
using namespace std;

/*

The algorithm starts with an empty spanning tree.
The idea is to maintain two sets of vertices.
The first set contains the vertices already included in the MST,
and the other set contains the vertices not yet included.
At every step, it considers all the edges that connect the two sets
and picks the minimum weight edge from these edges.
After picking the edge, it moves the other endpoint of the edge to the set containing MST.

*/

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> edges)
    {
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b)
             { return a[2] < b[2]; });
        vector<bool> vis(V, false);
        int ans = 0;
        vis[0] = true;
        for (int i = 1; i < V; i++)
        {
            for (auto edge : edges)
            {
                int u = edge[0], v = edge[1], w = edge[2];
                if (vis[u] && vis[v])
                    continue;
                if (vis[u] || vis[v])
                {
                    vis[u] = vis[v] = true;
                    ans += w;
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> mstSet(V, false);
    key[0] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int u = -1;
        for (int j = 0; j < V; j++)
        {
            if (!mstSet[j] && (u == -1 || key[j] < key[u]))
                u = j;
        }
        mstSet[u] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (!mstSet[v] && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
    return 0;
}