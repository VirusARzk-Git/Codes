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
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b, i};
    }
    sort(all(v), [](auto &a, auto &b)
         {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0]; });
    vi ans1(n), ans2(n);
    oset os;
    for (auto &x : v)
    {
        int start = x[0], end = x[1], idx = x[2];
        int c2 = os.order_of_key(end);
        ans2[idx] = os.size() - c2 ? 1 : 0;
        os.insert(end);
    }
    reverse(all(v));
    os.clear();
    for (auto &x : v)
    {
        int start = x[0], end = x[1], idx = x[2];
        int c1 = os.order_of_key(end + 1);
        ans1[idx] = c1 ? 1 : 0;
        os.insert(end);
    }
    out(ans1);
    cout << '\n';
    out(ans2);
    cout << '\n';
}

signed main()
{
    fast_faster_fastest;

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cout << setprecision(15) << fixed;
    int t = 1;
    while (t--)
        code();
    return 0;
}