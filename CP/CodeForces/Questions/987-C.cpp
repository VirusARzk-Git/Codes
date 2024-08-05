#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#pragma GCC target("popcnt")
#define int long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
// void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }

template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

#define B begin()
#define E end()
#define I iterator
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;
int myPow(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int modPow(int a, int b, int m)
{
    a %= m;
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = ans * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

typedef long double lld;
const int N = 1e7 + 2, M = 1e5 + 10, mod = 1e9 + 7, inf = 4e18, moda = 998244353;
const lld pi = 3.141592653589793;

vector<int> spf(N, 0);

void SPF()
{
    spf[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            for (int j = i * i; j < N; j += i)
                if (spf[j] == 0)
                    spf[j] = i;
        }
    }
}
int add(int a, int b, int m) { return (a + b) % m; }
int sub(int a, int b, int m) { return (a % m - b % m + m) % m; }
int mul(int a, int b, int m) { return ((a % m) * (b % m) * 1ll) % m; }
int inv(int a, int m) { return modPow(a, m - 2, m); }
int divi(int a, int b, int m) { return mul(a, inv(b, m), m); }

vi fact(M + 1);
void precomputeFactorial(int md)
{
    fact[0] = 1;
    for (int i = 1; i <= M; i++)
        fact[i] = mul(fact[i - 1], i, md);
}
int nCr(int n, int r, int md)
{
    if (r > n || r < 0)
        return 0;
    return divi(fact[n], mul(fact[r], fact[n - r], md), md);
}
int nCr(int n, int r)
{
    if (r > n || r < 0)
        return 0;
    if (r == 0 || r == n)
        return 1;
    if (r == 1)
        return n;
    if (r > n - r)
        r = n - r;
    int ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}

int countDigit(int n)
{
    return floor(log10(n) + 1);
}

#define yes cout << "Yes\n"
#define no cout << "No\n"
#define nnn \
    int n;  \
    cin >> n
#define all(x) x.begin(), x.end()
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define inArr          \
    vi arr(n);         \
    for (int &i : arr) \
    cin >> i
#define outArr        \
    for (int i : arr) \
    cout << i << ' '

void code()
{
    nnn;
    vi fs(n);
    for (int &i : fs)
        cin >> i;
    vi cost(n);
    for (int &i : cost)
        cin >> i;
    int dp[n + 1][4];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= 3; i++)
        dp[0][i] = inf;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1][1] = cost[i];
        for (int j = 2; j <= 3; j++)
        {
            dp[i + 1][j] = inf;
            for (int k = 0; k < i; k++)
            {
                if (fs[k] < fs[i] && dp[k + 1][j - 1] != inf)
                    dp[i + 1][j] = min(dp[i + 1][j], dp[k + 1][j - 1] + cost[i]);
            }
        }
    }
    int ans = inf;
    for (int i = 1; i <= n; i++)
        ans = min(ans, dp[i][3]);
    if (ans == inf)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}

signed main()
{
    noTLE;

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    while (t--)
        code();
    return 0;
}