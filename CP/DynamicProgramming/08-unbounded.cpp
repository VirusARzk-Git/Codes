#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int f(int n, vi &wt, vi &val, int W, vvi &memo)
{
    if (n == 0 || W == 0)
        return 0;
    if (memo[n][W] != -1)
        return memo[n][W];
    int pick = 0;
    if (wt[n - 1] <= W)
        pick = val[n - 1] + f(n, wt, val, W - wt[n - 1], memo);
    int notPick = f(n - 1, wt, val, W, memo);
    return memo[n][W] = max(pick, notPick);
}

int tabulation(int n, vi &wt, vi &val, int W)
{
    vvi dp(n + 1, vi(W + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

int main()
{
    int n;
    cin >> n;
    vi wt(n), val(n);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int W;
    cin >> W;
    vvi memo(n + 1, vi(W + 1, -1));
    cout << f(n, wt, val, W, memo) << endl;
}