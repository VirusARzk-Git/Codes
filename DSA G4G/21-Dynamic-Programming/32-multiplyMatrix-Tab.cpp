#include <iostream>
using namespace std;

int mChain(int *arr, int n)
{
    int dp[n][n] = {0};
    for (int gap = 2; gap < n; gap++)
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i] * arr[j] * arr[k]);
        }
    return dp[0][n - 1];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << mChain(arr, n);
}