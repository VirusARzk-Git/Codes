#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nodes;    cin >> nodes;
    vector<vector<int>> g(nodes);
    // Java -> ArrayList<ArrayList<Integer>> g = new ArrayList<>(nodes);

    int edges;    cin >> edges;

    while (edges--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        // g[u].add(v);
        // g[v].add(u);
    }

    for(int i = 0; i < nodes; i++)
    {
        cout << i << " -> ";
        for (auto x : g[i])
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
