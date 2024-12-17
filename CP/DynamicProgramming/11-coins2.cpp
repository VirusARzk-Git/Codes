using vi = vector<int>;
using vvi = vector<vi>;
class Solution
{
    int f(int n, int amt, vvi &memo, vi &coins)
    {
        if (amt == 0)
            return 0;
        if (n == 0)
            return 1e9;
        if (memo[n][amt] != -1)
            return memo[n][amt];
        int pick = 1e9;
        if (coins[n - 1] <= amt)
            pick = 1 + f(n, amt - coins[n - 1], memo, coins);
        int notPick = f(n - 1, amt, memo, coins);
        return memo[n][amt] = min(pick, notPick);
    }

public:
    int coinChange(vector<int> &coins, int amt)
    {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vvi memo(n + 1, vi(amt + 1, -1));
        int ans = f(n, amt, memo, coins);
        return ans == -1 ? -1 : ans;
    }
};

// Tabulation
class Solution
{
public:
    int coinChange(vector<int> &coins, int amt)
    {
        int n = coins.size();
        vvi dp(n + 1, vi(amt + 1, 1e9));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amt; j++)
            {
                int pick = 1e9;
                if (coins[i - 1] <= j)
                    pick = 1 + dp[i][j - coins[i - 1]];
                int notPick = dp[i - 1][j];
                dp[i][j] = min(pick, notPick);
            }
        }
        return dp[n][amt] == 1e9 ? -1 : dp[n][amt];
    }
};