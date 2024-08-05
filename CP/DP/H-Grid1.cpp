#include <bits/stdc++.h>
using namespace std;

void code()
{
    vector<string> v;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = (v[0][0] == '.');
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '#')
                continue;
            if (i > 0 && v[i - 1][j] != '*')
                dp[i][j] += dp[i - 1][j];
            if (j > 0 && v[i][j - 1] != '*')
                dp[i][j] += dp[i][j - 1];
            dp[i][j] %= 1000000007;
        }
    }
    cout << dp[n - 1][m - 1] << endl;
}

signed main()
{
    code();
    return 0;
}