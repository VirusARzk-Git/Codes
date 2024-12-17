// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution
{
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

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int x : nums)
            sum += x;
        if (sum % 2)
            return false;
        return isSubsetSum(nums, sum / 2);
    }
};