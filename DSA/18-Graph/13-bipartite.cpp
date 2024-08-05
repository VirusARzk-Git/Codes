#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
#define all(x) x.begin(), x.end()
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define debug(x)     \
    for (auto i : x) \
        cout << i << ' ';

void DFSRec(vector<int> *adj, int s, vector<int> &ans)
{
    for (int u : adj[s])
    {
        if (ans[u] == ans[s])
        {
            cout << "IMPOSSIBLE";
            exit(0);
        }
        else if (ans[u] == 0)
        {
            ans[u] = 3 - ans[s];
            DFSRec(adj, u, ans);
        }
    }
}

vector<int> DFS_disconnected(vector<int> *adj, int v, int s)
{
    vector<int> ans(v, 0);
    for (int i = 0; i < v; i++)
        if (ans[i] == 0)
        {
            ans[i] = 1;
            DFSRec(adj, i, ans);
        }
    return ans;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void code()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u - 1, v - 1);
    }
    vi v = DFS_disconnected(adj, n, 0);
    debug(v);
}

signed main()
{
    noTLE;
    code();
    return 0;
}