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
    string s;
    cin >> s;
    unordered_map<char, char> m;
    int n = s.size();
    if (s[0] == s[n - 1])
        no;
    else
    {
        int o = 0, c = 0, ex = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == s[0])
                o++;
            else if (s[i] == s[n - 1])
                c++;
            else
                ex++;
        }
        if (o != c + ex && c != o + ex)
            no;
        else
        {
            m[s[0]] = '(';
            m[s[n - 1]] = ')';
            unordered_set<char> st;
            st.insert('A');
            st.insert('B');
            st.insert('C');
            st.erase(s[0]);
            st.erase(s[n - 1]);
            char x = *st.begin();
            if (c < o)
                m[x] = ')';
            else
                m[x] = '(';
            for (int i = 0; i < n; i++)
                s[i] = m[s[i]];
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(')
                    cnt++;
                else
                    cnt--;
                if (cnt < 0)
                {
                    no;
                    return;
                }
            }
            if (cnt != 0)
                no;
            else
                yes;
        }
    }
}

signed main()
{
    noTLE;

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    tCases
    code();
    return 0;
}