#include <iostream>
#include <queue>
using namespace std;

vector<int> BFS(vector<int> *adj, int v, int s)
{
    vector<int> BFS;
    bool visited[v + 1] = {false};
    for (int i = 0; i < v; i++)
        visited[i] = false;
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

int main()
{
}