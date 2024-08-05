#include <iostream>
using namespace std;

int maxSum_with_NoConsecutives(int *arr, int i)
{
    if (i == 0)
        return arr[0];
    if (i == 1)
        return max(arr[0], arr[1]);
    return max(maxSum_with_NoConsecutives(arr, i - 1), arr[i] + maxSum_with_NoConsecutives(arr, i - 2));
}

int maxSum_with_NoConsecutives_Tabulation(int *arr, int n)
{
    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
    return dp[n - 1];
}

int maxSum_with_NoConsecutives_Tabulation_Optimized(int *arr, int n)
{
    int prev_prev = arr[0], prev = max(arr[0], arr[1]), res;
    for (int i = 2; i < n; i++)
        res = max(prev, arr[i] + prev_prev), prev_prev = prev, prev = res;
    return res;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxSum_with_NoConsecutives_Tabulation_Optimized(arr, n);
}