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
#define debug(x) \
    //     for (auto i : x) \
//         cout << i << ' '; \
    // #define debugln(x)   \
//     for (auto i : x) \
//         cout << i << endl;

void NSE(vi arr, vi &nse)
{
    int n = arr.size();
    stack<int> s;
    nse[n - 1] = n;
    s.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (s.empty())
            nse[i] = n;
        else
            nse[i] = s.top();
        s.push(i);
    }
    debug(nse);
}

void PSE(vi arr, vi &pse)
{
    int n = arr.size();
    stack<int> s;
    pse[0] = -1;
    s.push(0);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (s.empty())
            pse[i] = -1;
        else
            pse[i] = s.top();
        s.push(i);
    }
    debug(pse);
}

void ANSWER(vi arr, vector<vi> &sol)
{
    int n = arr.size();
    vector<int> nse(n), pse(n);
    PSE(arr, pse);
    NSE(arr, nse);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // int l = nse[i] - pse[i] - 1;
        // cout << arr[i] << ' ' << l << endl;
        if (arr[i])
            sol[arr[i] - 1][nse[i] - pse[i] - 2]++;
        // cout << l << ' ';
    }
    cout << endl;
}

void code()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> sol(n, vector<int>(m));
    char c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            if (c == '*')
                arr[i][j] = 0;
            else
            {
                if (i == 0)
                    arr[i][j] = 1;
                else
                    arr[i][j] = arr[i - 1][j] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
        ANSWER(arr[i], sol);
    for (vi v : sol)
    {
        for (int i : v)
            cout << i << ' ';
        cout << endl;
    }
}

signed main()
{
    code();
    return 0;
}