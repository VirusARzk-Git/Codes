#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFSRec(vector<int> *adj, int s, vector<bool> &visited,  stack<int> &st)
{
    visited[s] = true;
    for (int u : adj[s])
        if (!visited[u])
            DFSRec(adj, u, visited, st);
    st.push(s);
}

vector<int> topoSort_DFS(vector<int> *adj, int v)
{
    vector<bool> visited(v, false);
    stack<int> st;
    vector<int> ans;
    for (int i = 0; i < v; i++)
        if (!visited[i])
            DFSRec(adj, i, visited,  st);
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
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
    addEdge(adj, 1, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);
    vector<int> tpS = topoSort_DFS(adj, v);
    for (int i : tpS)
        cout << i << ' ';
}