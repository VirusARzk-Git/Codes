#include <bits/stdc++.h>
#define int long long
using namespace std;

using vi = vector<int>;

void code()
{
    int n, w;
    cin >> n >> w;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= w; j++)
            if (wt[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
    cout << dp[n][w];
}

signed main()
{
    code();
    return 0;
}