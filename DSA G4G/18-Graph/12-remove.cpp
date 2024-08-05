
int topoSort(vector<int> *adj, int vertices)
{
    vector<int> degree(vertices, 0);
    vector<int> ans;
    for (int i = 0; i < vertices; i++)
        for (int u : adj[i])
            degree[u]++;
    queue<int> q;
    for (int i = 0; i < vertices; i++)
        if (degree[i] < 2)
            q.push(i);
    int t = 0;
    while (!q.empty())
    {
        queue<int> qq;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                degree[v]--;
                if (degree[v] == 1)
                    q.push(v);
            }
        }
        q = qq;
        t++;
    }
    return t;
}