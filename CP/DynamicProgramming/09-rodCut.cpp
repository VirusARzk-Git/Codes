// https://www.naukri.com/code360/costoblems/rod-cutting-costoblem_800284

using vi = vector<int>;
using vvi = vector<vi>;
int f(int n, vi &cost, int L, vvi &memo)
{
    if (n == 0 || L == 0)
        return 0;
    if (memo[n][L] != -1)
        return memo[n][L];
    int pick = 0;
    if (n <= L)
        pick = cost[n - 1] + f(n, cost, L - n, memo);
    int notPick = f(n - 1, cost, L, memo);
    return memo[n][L] = max(pick, notPick);
}

int cutRod(vector<int> &cost, int n)
{
    vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
    return f(n, cost, n, memo);
}

// tabulation

int cutRod(vector<int> &cost, int N)
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    for (int n = 1; n <= N; n++)
    {
        for (int L = 1; L <= N; L++)
        {
            int pick = 0, notPick = 0;
            notPick = dp[n - 1][L];
            if (n <= L)
                pick = cost[n - 1] + dp[n][L - n];
            dp[n][L] = max(pick, notPick);
        }
    }
    return dp[N][N];
}