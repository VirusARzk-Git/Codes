#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
int answer(vector<vector<int>> &a)
{
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = a[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = a[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = a[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }
    return max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    cout << answer(a);
    return 0;
}