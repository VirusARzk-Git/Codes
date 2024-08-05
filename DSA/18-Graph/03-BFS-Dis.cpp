#include <iostream>
#include <queue>
using namespace std;

vector<int> BFS(vector<int> *adj, int s, vector<bool> &visited)
{
    vector<int> BFS;
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        BFS.push_back(u);
        for (int v : adj[u])
            if (visited[v] == false)
                visited[v] = true, q.push(v);
    }
    return BFS;
}

vector<int> BFS_Dis(vector<int> *adj, int v)
{
    vector<int> bfs;
    vector<bool> visited(v + 1, false);
    for (int i = 0; i < v; i++)
        if (!visited[i])
        {
            vector<int> v = BFS(adj, i, visited);
            for (int i : v)
                bfs.push_back(i);
        }
    return bfs;
}

int main()
{
}