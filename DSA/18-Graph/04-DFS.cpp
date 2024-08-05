#include <iostream>
#include <queue>
using namespace std;

void DFSRec(vector<int> *adj, int s, vector<bool> &visited, vector<int> &ans)
{
    visited[s] = true;
    ans.push_back(s);
    for (int u : adj[s])
        if (!visited[u])
            DFSRec(adj, u, visited, ans);
}

vector<int> DFS(vector<int> *adj, int v, int s)
{
    vector<bool> visited(v, false);
    vector<int> ans;
    DFSRec(adj, s, visited, ans);
    return ans;
}

vector<int> DFS_disconnected(vector<int> *adj, int v, int s)
{
    vector<bool> visited(v, false);
    vector<int> ans;
    for (int i = 0; i < v; i++)
        if (!visited[i])
            DFSRec(adj, i, visited, ans);
    return ans;
}

int main()
{
}