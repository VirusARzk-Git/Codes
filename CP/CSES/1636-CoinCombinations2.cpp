#include <bits/stdc++.h>
using namespace std;

#define int long long

using vi = vector<int>;
#define all(x) x.begin(), x.end()
#define inArr                   \
    vi arr(n);                  \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

void code()
{
    int n, x;
    cin >> n >> x;
    inArr;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int c : arr)
        for (int i = 1; i <= x; i++)
            if (i >= c)
                (dp[i] += dp[i - c]) %= 1000000007;
    cout << dp[x];
}

signed main()
{
    code();
    return 0;
}