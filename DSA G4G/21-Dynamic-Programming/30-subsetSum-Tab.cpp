#include <iostream>
using namespace std;

int countSubsets(int *arr, int n, int target)
{
    int dp[n + 1][target + 1] = {0};
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= target; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (arr[i - 1] <= j)
                dp[i][j] += dp[i - 1][j - arr[i - 1]];
        }
    return dp[n][target];
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cin >> target;
    cout << countSubsets(arr, n, target);
}