#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;

vpii swaps = {{0, 1}, {1, 2}, {3, 4}, {4, 5}, {6, 7}, {7, 8}, {0, 3}, {3, 6}, {1, 4}, {4, 7}, {2, 5}, {5, 8}};

void code()
{
    string s;
    int n = 9;
    while (n--)
    {
        char ch;
        cin >> ch;
        s.push_back(ch);
    }
    n = 9;
    string target = "123456789";
    queue<pair<int, string>> pq;
    unordered_set<string> vis;
    pq.push({0, s});
    vis.insert(s);
    while (!pq.empty())
    {
        int cost = pq.front().first;
        string cur = pq.front().second;
        pq.pop();
        if (cur == target)
        {
            cout << cost << '\n';
            return;
        }
        for (auto &[i, j] : swaps)
        {
            swap(cur[i], cur[j]);
            if (vis.find(cur) == vis.end())
            {
                vis.insert(cur);
                pq.push({cost + 1, cur});
            }
            swap(cur[i], cur[j]);
        }
    }
}

signed main()
{
    code();
    return 0;
}