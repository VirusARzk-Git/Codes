class UnionFind
{
    vector<int> parent;
    int distinctComponents;

public:
    UnionFind(int n)
    {
        distinctComponents = n;
        for (int i = 0; i <= n; i++)
            parent.push_back(i);
    }

    bool unite(int a, int b)
    {
        if (findComponent(a) == findComponent(b))
            return false;
        parent[findComponent(a)] = b;
        distinctComponents--;
        return true;
    }

    int findComponent(int a)
    {
        if (parent[a] != a)
            parent[a] = findComponent(parent[a]);
        return parent[a];
    }

    bool united() { return distinctComponents == 1; }

    int findDistinctComponents() { return distinctComponents; }
};