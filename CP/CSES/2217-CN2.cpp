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
void _print(T t, V... s)
{
    __print(t);
    if (sizeof...(s))
        cerr << ", ";
    _print(s...);
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
int myPow(int x, int y)
{
    int ans = 1;
    while (y > 0)
    {
        if (y & 1)
            ans = ans * x;
        x = x * x;
        y >>= 1;
    }
    return ans;
}

int modPow(int x, int y, int m)
{
    x %= m;
    int ans = 1;
    while (y > 0)
    {
        if (y & 1)
            ans = ans * x % m;
        x = x * x % m;
        y >>= 1;
    }
    return ans;
}

int gcd(int x, int y)
{
    while (y)
    {
        x %= y;
        swap(x, y);
    }
    return x;
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
int add(int x, int y, int m) { return (x + y) % m; }
int sub(int x, int y, int m) { return (x % m - y % m + m) % m; }
int mul(int x, int y, int m) { return ((x % m) * (y % m) * 1ll) % m; }
int inv(int x, int m) { return modPow(x, m - 2, m); }
int divi(int x, int y, int m) { return mul(x, inv(y, m), m); }

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
#define inArr        \
    vi a(n);         \
    for (int &i : a) \
    cin >> i
#define outArr      \
    for (int i : a) \
    cout << i << ' '

void code()
{
    vector<int> a, ind;
    int n, m;
    cin >> n >> m;
    a.resize(n + 1);
    ind.resize(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ind[a[i]] = i;
    }
    ind[n + 1] = n + 1;
    int ans = 1;
    for (int i = 2; i <= n; i++)
        if (ind[i] < ind[i - 1])
            ans++;
    // cout << ans << endl;
    // debug(a);
    // debug(ind);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        int r = a[x], s = a[y];
        swap(a[x], a[y]);
        debug(r, s);
        if (ind[r - 1] < x && ind[r - 1] >= y)
            ans++;
        if (ind[r - 1] > x && ind[r - 1] <= y)
            ans--;
        if (x < ind[r + 1] && y >= ind[r + 1])
            ans++;
        if (x > ind[r + 1] && y <= ind[r + 1])
            ans--;
        ind[r] = y;
        if (ind[s - 1] < y && ind[s - 1] >= x)
            ans++;
        if (ind[s - 1] > y && ind[s - 1] <= x)
            ans--;
        if (y < ind[s + 1] && x >= ind[s + 1])
            ans++;
        if (y > ind[s + 1] && x <= ind[s + 1])
            ans--;
        ind[s] = x;
        debug(a);
        // debug(ind);
        cout << ans << '\n';
    }
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