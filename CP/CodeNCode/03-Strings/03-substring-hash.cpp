#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define int long long
int dp[1000001];
int inv[1000001];

int power(int a, int n)
{
    int result = 1;
    while (n)
    {
        if (n & 1)
            result = (result * a) % mod;
        n >>= 1;
        a = (a * a) % mod;
    }
    return result;
}

int substringHash(int L, int R)
{
    int result = dp[R];
    if (L > 0)
        result -= dp[L - 1];
    result = (result * inv[L]) % mod;
    return result;
}

void init(string s)
{
    int p = 31;
    int p_power = 1;
    inv[0] = 1;
    dp[0] = s[0] - 'a' + 1;

    int n = s.size();
    REP(i, n - 1)
    {
        char ch = s[i];
        p_power = (p_power * p) % mod;
        inv[i] = power(p_power, mod - 2);
        dp[i] = (dp[i - 1] + (ch - 'a' + 1) * p_power) % mod;
    }
}

signed main()
{
    string input_string;
    int tc, L, R;
    cin >> input_string;
    init(input_string);
    cin >> tc;
    REP(i, tc)
    {
        cin >> L >> R;
        cout << substringHash(L, R) << endl;
    }
    return 0;
}