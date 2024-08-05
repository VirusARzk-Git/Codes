#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> *adj, int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

vector<int> dijkstra(int V, vector<vector<int>> *adj, int S)
{
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto it : adj[u])
        {
            int v = it[0];
            int weight = it[1];
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    int V = 5;
    vector<vector<int>> adj[V];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 2, 4, 7);
    addEdge(adj, 3, 4, 9);
    vector<int> ans = dijkstra(V, adj, 0);
    for (int i : ans)
        cout << i << ' ';
}