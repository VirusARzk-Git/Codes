#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void code()
{
    int n, k;
    cin >> n >> k;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vi dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= k; j++)
            if (i - j >= 0)
                dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
    cout << dp[n - 1];
}

signed main()
{
    code();
    return 0;
}