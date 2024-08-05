
#include <bits/stdc++.h>
using namespace std;

#define B begin()
#define E end()
#define I iterator
using pii = pair<int, int>;
using vi = vector<int>;
#define int long long
typedef long double lld;
const int N = 1e7 + 2, M = 1e5 + 10, mod = 1e9 + 7, inf = 4e18, moda = 998244353;
const lld pi = 3.141592653589793;
#define all(x) x.begin(), x.end()
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)
#define array_input_lelo_bhai   \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define array_print_kardo_bhai  \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '
#include <stdio.h>
// #include <conio.h>
int code_iske_andar_hai()
{
    string s;
    // getline(s);
    cin >> s;
    int n = s.length();
    int first = 0, last = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
        {
            first = i;
            break;
        }
    for (int i = n - 1; i > 0; i--)
        if (s[i] == '0')
        {
            last = i;
            break;
        }
    int x = first + n - 1 - last;
    int c = 0, mx = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            c++, mx = max(mx, c);
        else
            c = 0;
    mx = max(mx, x);
    // cout << mx << endl;
    if (mx == n)
        return n * n;
    else if (mx == 1)
        return 1;
    else if (mx == 0)
        return 0;
    else
    {
        int ans = 0, inc = 1;
        for (int i = 0; i < mx + 1;)
        {
            if (i == mx)
                return ans;
            else
                ans += inc, i++;
            if (i == mx)
                return ans;
            else
                ans += inc, i++;
            inc++;
        }
    }
    return 0;
}

signed main()
{
    noTLE;
    testcase_chalao_bhai
            cout
        << code_iske_andar_hai() << endl;
    return 0;
}