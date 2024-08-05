#include <bits/stdc++.h>
using namespace std;

#define int long long

using vi = vector<int>;
#define nnn \
    int n;  \
    cin >> n
#define all(x) x.begin(), x.end()
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define inArr                   \
    vi arr(n);                  \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define debug(x)     \
    for (auto i : x) \
        cout << i << ' ';

void code()
{
    nnn;
    inArr;
    int sum = accumulate(all(arr), 0);
    sort(all(arr));
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    set<int> s;
    s.insert(0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + arr[i - 1];
            // cout << dp[i][j] << ' ';
            s.insert(dp[i][j]);
        }
    }
    // cout << dp[n][sum] - sum;
    s.erase(0);
    cout << s.size() << endl;
    debug(s);
}

signed main()
{
    noTLE;

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // tCases
    code();
    return 0;
}