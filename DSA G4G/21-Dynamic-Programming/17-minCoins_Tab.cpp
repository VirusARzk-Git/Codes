#include <iostream>
#include <vector>
using namespace std;

int getMinCoins(int *coins, int n, int amt)
{
    int *dp = new int[amt + 1];
    dp[0] = 0;
    for (int i = 1; i <= amt; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++)
            if (i >= coins[j] && dp[i - coins[j]] != INT_MAX)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    }
    if (dp[amt] == INT_MAX)
        return -1;
    return dp[amt];
}

int main()
{
    int n;
    cin >> n;
    int *coins = new int[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int amt;
    cin >> amt;
    cout << getMinCoins(coins, n, amt);
}