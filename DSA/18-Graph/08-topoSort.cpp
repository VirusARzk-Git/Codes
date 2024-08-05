#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Kahn's Algorithm

vector<int> topoSort(vector<int> *adj, int vertices)
{
    vector<int> inDegree(vertices, 0);
    vector<int> ans;
    for (int i = 0; i < vertices; i++)
        for (int u : adj[i])
            inDegree[u]++;
    queue<int> q;
    for (int i = 0; i < vertices; i++)
        if (inDegree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v : adj[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }
    return ans;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 4);
    vector<int> ans = topoSort(adj, v);
    for (int i : ans)
        cout << i << ' ';
}