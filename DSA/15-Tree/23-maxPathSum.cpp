// Max sum of any tree path

int ans;
vector<vector<int>> g;
int dfs(int u, vector<int> &val)
{
    int sum = val[u];
    int a1 = 0, a2 = 0;
    for (int v : g[u])
    {
        int x = dfs(v, val);
        if (x >= a1)
            a2 = a1, a1 = x;
        else
            a2 = max(a2, x);
    }
    ans = max(ans, val[u] + a1 + a2);
    return a1 + val[u];
}

int bestSumAnyTreePath(vector<int> &parents, vector<int> &val)
{
    int n = parents.size();
    g.clear();
    g.resize(n);
    for (int i = 1; i < n; ++i)
        g[parents[i]].push_back(i);
    dfs(0, val);
    return ans;
}
