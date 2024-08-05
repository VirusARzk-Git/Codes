#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("popcnt")
#define int long long unsigned

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
    int m, n;
    cin >> m >> n;
    vi t(n), z(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> t[i] >> z[i] >> y[i];
    vi ans(n, 0);
    if (m == 0)
    {
        cout << 0 << endl;
        for (auto i : ans)
            cout << 0 << ' ';
        return;
    }
    int left = 0, right = LLONG_MAX;
    int time = LLONG_MAX;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        vi temp(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x = z[i] * t[i] + y[i];
            int c = (mid / x) * z[i];
            int r = mid % x;
            if (r >= t[i] * z[i])
                c += z[i];
            else
                c += r / t[i];
            sum += c;
            temp[i] = c;
        }
        if (sum >= m)
        {
            right = mid - 1;
            time = min(time, mid);
            ans = temp;
        }
        else
            left = mid + 1;
    }
    cout << time << endl;
    int sm = accumulate(all(ans), 0);
    int mns = max(0ull, sm - m);
    for (int i = 0; i < n; i++)
    {
        if (mns == 0)
            break;
        int mxx = min(ans[i], mns);
        ans[i] -= mxx;
        mns -= mxx;
    }
    for (auto i : ans)
        cout << i << ' ';
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