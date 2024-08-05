#include <iostream>
using namespace std;

int minJumps(int *arr, int n)
{
    int *dp = new int[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
        dp[i] = INT_MAX;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[j] + j >= i)
                if (dp[j] != INT_MAX)
                    dp[i] = min(dp[i], dp[j] + 1);
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minJumps(arr, n);
}