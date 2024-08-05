#include <bits/stdc++.h>
using namespace std;

void code()
{
    vector<string> v;
    int h, w, n;
    cin >> h >> w >> n;
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        s.insert(pair<int, int>(a - 1, b - 1));
    }
    vector<vector<int>> dp(h, vector<int>(w, 0));
    dp[0][0] = (1 - s.count({0, 0}));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s.find({i, j}) != s.end())
                continue;
            if (i > 0 && s.find({i - 1, j}) == s.end())
                dp[i][j] += dp[i - 1][j];
            if (j > 0 && s.find({i, j - 1}) == s.end())
                dp[i][j] += dp[i][j - 1];
            dp[i][j] %= 1000000007;
        }
    }
    cout << dp[h - 1][w - 1] << endl;
}

signed main()
{
    code();
    return 0;
}