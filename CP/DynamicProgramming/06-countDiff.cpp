// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/0

class Solution
{
    const int mod = 1e9 + 7;

public:
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if ((sum + d) % 2 != 0 || sum < d)
            return 0;
        int k = (sum - d) / 2;
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
};