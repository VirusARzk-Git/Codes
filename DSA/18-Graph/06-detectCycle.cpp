#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//----------------------        Undirected Graph

bool DFSRec(vector<int> *adj, int s, vector<bool> &visited, int parent)
{
    visited[s] = true;
    for (int u : adj[s])
        if (!visited[u])
        {
            if (DFSRec(adj, u, visited, s))
                return true;
        }
        else if (u != parent)
            return true;
    return false;
}

bool detectCycle(vector<int> *adj, int v)
{
    vector<bool> visited(v, false);
    vector<int> ans;
    for (int i = 0; i < v; i++)
        if (!visited[i])
            if (DFSRec(adj, i, visited, -1))
                return true;
    return false;
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
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 5, 4);
    cout << detectCycle(adj, v);
}