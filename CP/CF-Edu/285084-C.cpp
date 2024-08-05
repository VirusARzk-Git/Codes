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
    int k;
    cin >> k;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vi brr(n);
    for (int i = 0; i < n; i++)
        cin >> brr[i];
    sort(all(arr));
    sort(all(brr));
    int ans = 0;
    int left = arr[0] + brr[0];
    int right = arr[n - 1] + brr[n - 1];
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= mid)
                break;
            cnt += upper_bound(all(brr), mid - arr[i]) - brr.B;
        }
        // cout << mid << ' ' << cnt << endl;
        if (cnt >= k)
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    cout << ans << endl;
}

signed main()
{
    noTLE;

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //  tCases
    code();
    return 0;
}