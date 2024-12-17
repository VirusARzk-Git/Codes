// https://leetcode.com/problems/coin-change-ii/

using vi = vector<int>;
using vvi = vector<vi>;

// Recursive

class Solution
{
    vi coins;
    int n;
    int f(int n, int amt, vvi &memo)
    {
        if (amt == 0)
            return 1;
        if (n == 0)
            return 0;
        if (memo[n][amt] != -1)
            return memo[n][amt];
        int pick = coins[n - 1] <= amt ? f(n, amt - coins[n - 1], memo) : 0;
        int notPick = f(n - 1, amt, memo);
        return memo[n][amt] = pick + notPick;
    }

public:
    int change(int amt, vector<int> &coins_)
    {
        coins = coins_;
        n = coins.size();
        vvi memo(n + 1, vi(amt + 1, -1));
        return f(n, amt, memo);
    }
};

// Iterative
class Solution
{
public:
    int change(int amt, vector<int> &coins)
    {
        int n = coins.size();
        vvi dp(n + 1, vi(amt + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amt; j++)
            {
                int pick = coins[i - 1] <= j ? dp[i][j - coins[i - 1]] : 0;
                int notPick = dp[i - 1][j];
                dp[i][j] = pick + notPick;
            }
        }
        return dp[n][amt];
    }
};
