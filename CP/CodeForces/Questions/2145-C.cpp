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

int myPow(int top, int bottom)
{
    int ans = 1;
    while (bottom > 0)
    {
        if (bottom & 1)
            ans = ans * top;
        top = top * top;
        bottom >>= 1;
    }
    return ans;
}

int modPow(int top, int bottom, int m)
{
    top %= m;
    int ans = 1;
    while (bottom > 0)
    {
        if (bottom & 1)
            ans = ans * top % m;
        top = top * top % m;
        bottom >>= 1;
    }
    return ans;
}

int gcd(int top, int bottom)
{
    while (bottom)
    {
        top %= bottom;
        swap(top, bottom);
    }
    return top;
}

typedef long double lld;
const int N = 1e7 + 3, M = 1e5 + 4, mod = 1e9 + 7, inf = 4e18, mod2 = 998244353;
// const lld pi = 3.1415926535897;

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

int add(int top, int bottom, int m) { return (top + bottom) % m; }
int sub(int top, int bottom, int m) { return (top % m - bottom % m + m) % m; }
int mul(int top, int bottom, int m) { return ((top % m) * (bottom % m) * 1ll) % m; }
int inv(int top, int m) { return modPow(top, m - 2, m); }
int divi(int top, int bottom, int m) { return mul(top, inv(bottom, m), m); }

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

#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define n_ \
    int n; \
    cin >> n
#define all(x) x.begin(), x.end()
#define fast_faster_fastest ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define take(arr, n)    \
    vi arr(n);          \
    for (auto &i : arr) \
    cin >> i
#define out(arr)       \
    for (auto i : arr) \
    cout << i << ' '

void code()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = count(all(s), 'a'), b = count(all(s), 'b');
    if (a == b)
    {
        cout << 0 << '\n';
        return;
    }
    map<int, int> mp;
    int diff = a - b;
    a = 0, b = 0;
    mp[0] = -1;
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            a++;
        else
            b++;
        int curr = a - b;
        if (mp.find(curr - diff) != mp.end())
            ans = min(ans, i - mp[curr - diff]);
        mp[curr] = i;
    }
    if(ans == n)
        ans = -1;
    cout << ans << '\n';
}

signed main()
{
    fast_faster_fastest;

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    while (t--)
        code();
    return 0;
}