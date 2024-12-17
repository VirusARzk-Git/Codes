// https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532

const int mod = 1e9 + 7;

int f(int n, vector<int> &arr, int sum, vector<vector<int>> &memo)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    if (memo[n][sum] != -1)
        return memo[n][sum];
    int pick = 0, notPick = 0;
    if (arr[n - 1] <= sum && arr[n - 1] > 0)
        pick = f(n - 1, arr, sum - arr[n - 1], memo);
    notPick = f(n - 1, arr, sum, memo);
    return memo[n][sum] = (pick + notPick) % mod;
}

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
    int ans = f(n, arr, k, memo);
    for (int i = 0; i < n; i++)
        if (arr[i] == 0)
            (ans *= 2) %= mod;
    return ans;
}

// Tabulation

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
        {
            if (arr[i - 1] <= j && arr[i - 1] > 0)
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % mod;
            else
                dp[i][j] = dp[i - 1][j];
        }
    int ans = dp[n][k];
    for (int i = 0; i < n; i++)
        if (arr[i] == 0)
            (ans *= 2) %= mod;
    return ans;
}
