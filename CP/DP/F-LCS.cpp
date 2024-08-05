#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void code()
{
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.size(), n = s2.size();
    map<pii, pii> mp;
    mp[{1, 1}] = {0, 0};
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                mp[{i, j}] = {i - 1, j - 1};
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                    mp[{i, j}] = {i - 1, j};
                else
                    mp[{i, j}] = {i, j - 1};
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
    string ans = "";
    pii p = {m, n};
    while (mp.find(p) != mp.end())
    {
        pii p2 = mp[p];
        if (dp[p.first][p.second] > dp[p2.first][p2.second])
            ans += s1[p.first - 1];
        p = p2;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}

signed main()
{
    code();
    return 0;
}