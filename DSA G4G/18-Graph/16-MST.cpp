class DSU
{
private:
    vector<int> parent;

public:
    DSU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y)
    {
        int u = find(x);
        int v = find(y);
        if (u != v)
            if (u < v)
                parent[v] = u;
            else
                parent[u] = v;
    }

    void sett(int x, int y) { parent[x] = y; }
};

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> edges[])
    {
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b)
             { return a[2] < b[2]; });
        DSU dsu(V);
        int ans = 0;
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dsu.find(u) != dsu.find(v))
            {
                dsu.unionSets(u, v);
                ans += w;
            }
        }
        return ans;
    }
};