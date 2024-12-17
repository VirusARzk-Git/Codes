// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1


// Memoization

class Solution
{
    bool f(int n, vector<int> &arr, int sum, vector<vector<int>> &memo)
    {
        if (sum == 0)
            return 1;
        if (n == 0)
            return 0;
        if (memo[n][sum] != -1)
            return memo[n][sum];
        bool pick = 0, notPick = 0;
        if (arr[n - 1] <= sum)
            pick = f(n - 1, arr, sum - arr[n - 1], memo);
        notPick = f(n - 1, arr, sum, memo);
        return memo[n][sum] = pick || notPick;
    }

public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> memo(n + 1, vector<int>(sum + 1, -1));
        return f(n, arr, sum, memo);
    }
};

// Tabulation
class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};