#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestDist(vector<int> *adj, int v, int s)
{
    vector<int> dist(v, INT_MAX);
    dist[s] = 0;
    queue<int> q;
    vector<bool> visited(v, false);
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (visited[v] == false)
            {
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
            }
    }
    return dist;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    addEdge(adj, 5, 4);
    vector<int> dist = shortestDist(adj, v, 0);
    for (int a : dist)
        cout << a << ' ';
}