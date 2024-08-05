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
    sort(all(arr));
    vector<int> dp(x + 1, 0);
    for (int i = 1; i <= x; i++)
    {
        dp[i] = INT_MAX;
        for (int c : arr)
            if (i >= c)
                dp[i] = min(dp[i], dp[i - c] + 1);
    }
    if (dp[x] != INT_MAX)
        cout << dp[x];
    else
        cout << -1;
}

signed main()
{
    code();
    return 0;
}