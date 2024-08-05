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
void _print() { cerr << "]\t"; }

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
int nCr(int t, int r, int md)
{
    if (r > t || r < 0)
        return 0;
    return divi(fact[t], mul(fact[r], fact[t - r], md), md);
}
int nCr(int t, int r)
{
    if (r > t || r < 0)
        return 0;
    if (r == 0 || r == t)
        return 1;
    if (r == 1)
        return t;
    if (r > t - r)
        r = t - r;
    int ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans *= t - r + i;
        ans /= i;
    }
    return ans;
}

int countDigit(int t)
{
    return floor(log10(t) + 1);
}

#define yes cout << "Yes\t"
#define no cout << "No\t"
#define nnn \
    int t;  \
    cin >> t
#define all(x) x.begin(), x.end()
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define inArr          \
    vi arr(t);         \
    for (int &i : arr) \
    cin >> i
#define outArr        \
    for (int i : arr) \
    cout << i << ' '

void code()
{
    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;
    int c = 0;
    int dp[t + 1][1000];
    for (int i = 0; i <= t; i++)
        for (int j = 0; j < 1000; j++)
            dp[i][j] = INT_MIN;
    dp[0][v1] = 0;
    for (int i = 0; i < t; i++)
        for (int j = 0; j < 1000; j++)
            if (dp[i][j] != -1)
                for (int k = -d; k <= d; k++)
                {
                    // c++;
                    if (j + k >= 0 && j + k < 1000)
                        dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + j);
                }
    cout << dp[t - 1][v2] + v2;
    debug(c);
}

signed main()
{
    noTLE;

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cout << setprecision(15) << fixed;
    int t = 1;
    // cin>> t;
    while (t--)
        code();
    return 0;
}