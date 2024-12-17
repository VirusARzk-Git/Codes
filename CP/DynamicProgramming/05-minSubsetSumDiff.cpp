// https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

vector<bool> s;
int f(vector<int> &arr, int n, int sum, int pathsum, vector<vector<int>> &memo)
{
    if (n == 0)
        return abs(sum - 2 * pathsum);
    if (memo[n][pathsum] != -1)
        return memo[n][pathsum];
    int pick = f(arr, n - 1, sum, pathsum + arr[n - 1], memo);
    int leave = f(arr, n - 1, sum, pathsum, memo);
    return memo[n][pathsum] = min(pick, leave);
}

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i : arr)
        sum += i;
    vector<vector<int>> memo(n + 1, vector<int>(sum + 1, -1));
    return f(arr, n, sum, 0, memo);
}

//  tabulation
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int diff = INT_MAX;
    for (int i = sum / 2; i >= 0; i--)
        if (dp[n][i])
            return sum - 2 * i;
    return diff;
}
