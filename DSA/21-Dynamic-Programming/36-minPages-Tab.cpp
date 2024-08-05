#include <iostream>
using namespace std;

int *prefixSum;
int sum(int *arr, int i, int n) { return prefixSum[n + 1] - prefixSum[i]; }

int minPages(int *arr, int n, int k)
{
    int dp[k + 1][n + 1] = {0};
    for (int i = 1; i <= n; i++)
        dp[1][i] = sum(arr, 0, i - 1);
    for (int i = 1; i <= k; i++)
        dp[i][1] = arr[0];
    for (int i = 2; i <= k; i++)
        for (int j = 2; j <= n; j++)
        {
            dp[i][j] = INT_MAX;
            for (int k = 1; k < j; k++)
                dp[i][j] = min(dp[i][j], max(dp[i - 1][k], sum(arr, k, j - 1)));
        }
    return dp[k][n];
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    prefixSum = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }
    int k;
    cin >> k;
    cout << minPages(arr, n, k) << endl;
}