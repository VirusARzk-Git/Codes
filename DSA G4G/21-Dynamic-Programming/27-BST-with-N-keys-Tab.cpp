#include <iostream>
using namespace std;

#define int unsigned long long

int countBST(int n)
{
    int dp[n + 1] = {1};
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i] += (dp[j - 1] * dp[i - j]);
    return dp[n];
}

// It can also be written as the n-th catalan number

signed main()
{
    int n;
    cin >> n;
    cout << countBST(n);
}