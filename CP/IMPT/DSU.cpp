class DSU
{
private:
    vector<int> parent;
    vector<int> sz;

public:
    DSU(int n)
    {
        parent.resize(n);
        sz.resize(n, 1);
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
        {
            if (sz[u] < sz[v])
                swap(u, v);
            parent[v] = u;
            sz[u] += sz[v];
        }
    }

    void sett(int x, int y) { parent[x] = y; }
};
