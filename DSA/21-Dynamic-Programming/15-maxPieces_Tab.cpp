#include <iostream>
#include <algorithm>
using namespace std;

int maxPieces(int n, int a, int b, int c)
{
    int dp[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -2;
        if (i - a >= 0)
            dp[i] = max(dp[i], dp[i - a]);
        if (i - b >= 0)
            dp[i] = max(dp[i], dp[i - b]);
        if (i - c >= 0)
            dp[i] = max(dp[i], dp[i - c]);
        dp[i]++;
    }
    return dp[n];
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << maxPieces(n, a, b, c) << endl;
}