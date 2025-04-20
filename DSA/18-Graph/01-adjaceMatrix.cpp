#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes;      cin >> nodes;
    vector<vector<int>> adjM(nodes, vector<int>(nodes, 0));
    int edges;    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjM[u][v] = adjM[v][u] = 1; // For undirected graph
    }

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
            cout << adjM[i][j] << " ";
        cout << endl;
    }
}