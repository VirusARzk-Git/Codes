
#include <iostream>
#include <vector>
using namespace std;
#define int long long int
#define mod 998244353
const int N = 1e7 + 2;
int dp[6][N] = {0};
void codeforces()
{
    int n, val, x, y, m, k;
    cin >> n >> val >> x >> y >> m >> k;
    int a[n] = {0};
    a[0] = val;
    for (int i = 1; i < n; i++)
        a[i] = ((a[i - 1] * x) % m + y) % m;
    for (int i = 0; i <= min(k, n - 1); i++)
        dp[i][i] = a[0];
    for (int i = 1; i <= n; i++)
        dp[0][i] = (dp[0][i - 1] + a[i]) % mod;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans ^= (dp[k][i] * i);
    cout << ans;
}

signed main()
{
    codeforces();
    return 0;
}