#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bridges;
vector<int> dist, low;
vector<vector<int>> graph;  
int time = 0;
void dfs(int curr, int par)
{
    dist[curr] = low[curr] = time++;
    for (int next : graph[curr])
    {
        if (next == par)
            continue;
        if (dist[next] == -1)
        {
            dfs(next, curr);
            low[curr] = min(low[curr], low[next]);
            if (low[next] > dist[curr])
                bridges.push_back({curr, next});
        }
        else
            low[curr] = min(low[curr], dist[next]);
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    graph.resize(n);
    for (auto &edge : connections)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    dist.assign(n, -1);
    low.assign(n, -1);
    dfs(0, -1);
    return bridges;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> connections(m, vector<int>(2));
    for (int i = 0; i < m; i++)
        cin >> connections[i][0] >> connections[i][1];
    vector<vector<int>> ans = criticalConnections(n, connections);
    for (auto &bridge : ans)
        cout << bridge[0] << " " << bridge[1] << endl;
    return 0;
}