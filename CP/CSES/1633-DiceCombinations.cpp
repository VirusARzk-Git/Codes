#include <bits/stdc++.h>
using namespace std;

#define int long long unsigned
const int mod = 1e9+7;

void code()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 6; j++)
            if (i >= j)
                (dp[i] += dp[i - j]) %= mod;
    cout << dp[n];
}

signed main()
{
    code();
    return 0;
}