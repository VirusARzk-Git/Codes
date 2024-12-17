// https://leetcode.com/problems/target-sum/

class Solution
{
public:
    int findTargetSumWays(vector<int> &arr, int target)
    {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        int ans = 0;
        for (int i = 0; i <= sum; i++)
        {
            int sum1 = i;
            int sum2 = sum - i;
            if (sum1 - sum2 == target)
                return dp[n][i];
        }
        return 0;
    }
};