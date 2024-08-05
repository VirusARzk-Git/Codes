#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("popcnt")
#define int long long

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

int countDigit(int n)
{
    return floor(log10(n) + 1);
}

#define B begin()
#define E end()
#define I iterator
using pii = pair<int, int>;
using vi = vector<int>;
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define nnn \
    int n;  \
    cin >> n
typedef long double lld;
const int N = 1e7 + 2, M = 1e5 + 10, mod = 1e9 + 7, inf = 4e18, moda = 998244353;
const lld pi = 3.141592653589793;
#define all(x) x.begin(), x.end()
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define tCases  \
    int tcc;    \
    cin >> tcc; \
    while (tcc--)
#define inArr                   \
    vi arr(n);                  \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define outArr                  \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '
#define debug(x)     \
    for (auto i : x) \
        cout << i << ' ';
#define debugln(x)   \
    for (auto i : x) \
        cout << i << endl;

void code()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    vi arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    unordered_map<int, int> m;
    for (int i = 0 + 1; i < n + 1; i++)
        m[arr[i]] = i;
    int ans = 1;
    for (int i = 1; i < n; i++)
        if (m[i] > m[i + 1])
        {
            // cout << i << ' ' << i + 1 << endl;
            ans++;
        }
    // cout << ans << endl;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int aa = arr[a];
        int bb = arr[b];
        
        swap(arr[a], arr[b]);
        m[aa] = b;
        m[bb] = a;
        cout << ans << endl;
    }
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