#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(vector<pair<int, int>> *adj, int vertices)
{
    vector<int> inDegree(vertices, 0);
    vector<int> ans;
    for (int i = 0; i < vertices; i++)
        for (auto u : adj[i])
            inDegree[u.first]++;
    queue<int> q;
    for (int i = 0; i < vertices; i++)
        if (inDegree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (auto v : adj[u])
        {
            inDegree[v.first]--;
            if (inDegree[v.first] == 0)
                q.push(v.first);
        }
    }
    return ans;
}

vector<int> shortestPath(vector<pair<int, int>> *adj, int vertices, int s)
{
    vector<int> ans(vertices, INT_MAX);
    vector<int> tpSort = topoSort(adj, vertices);
    ans[s] = 0;
    for (int v : tpSort)
        if (ans[v] != INT_MAX)
            for (auto u : adj[v])
                ans[u.first] = min(ans[u.first], ans[v] + u.second);
    for (int i = 0; i < vertices; i++)
        if (ans[i] == INT_MAX)
            ans[i] = -1;
    return ans;
}

void addEdge(vector<pair<int, int>> *adj, int u, int v, int wt)
{
    adj[u].push_back({v, wt});
}

int main()
{
    int v = 4;
    vector<pair<int, int>> adj[v];
    addEdge(adj, 0, 1, 1);
    addEdge(adj, 2, 3, 4);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 2);
    vector<int> ans = shortestPath(adj, v, 1);
    for (int i : ans)
        cout << i << ' ';
}