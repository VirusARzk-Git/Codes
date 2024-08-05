#include <iostream>
#include <vector>
using namespace std;

int getWays(int *coins, int n, int sum)
{
    vector<vector<int>> dp(sum + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= sum; i++)
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (coins[j - 1] <= i)
                dp[i][j] += dp[i - coins[j - 1]][j];
        }
    return dp[sum][n];
}

signed main()
{
    int n;
    cin >> n;
    int *coins = new int[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int amt;
    cin >> amt;
    cout << getWays(coins, n, amt);
}