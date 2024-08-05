#include <bits/stdc++.h>
using namespace std;

vector<int> parent, score, sz;
void DSU(int n)
{
    parent.resize(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    score.resize(n, 0);
    sz.resize(n, 1);
}

int find(int x)
{
    while (x != parent[x])
        x = parent[x];
    return x;
}

void unionSets(int x, int y)
{
    int u = find(x);
    int v = find(y);
    if (u == v)
        return;
    if (sz[u] < sz[v])
        swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
    score[v] -= score[u];
}

void addi(int x, int y)
{
    int u = find(x);
    score[u] += y;
}

int getScore(int x)
{
    int ans = 0;
    while (x != parent[x])
    {
        ans += score[x];
        x = parent[x];
    }
    return ans + score[x];
}

void code()
{
    int n, m;
    cin >> n >> m;
    DSU(n + 1);
    string a;
    while (m--)
    {
        cin >> a;
        if (a == "join")
        {
            int u, v;
            cin >> u >> v;
            unionSets(u, v);
        }
        else if (a == "get")
        {
            int u;
            cin >> u;
            cout << getScore(u) << '\n';
        }
        else
        {
            int u, v;
            cin >> u >> v;
            addi(u, v);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    code();
    return 0;
}