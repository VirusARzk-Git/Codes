
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

bool isSubsequence(string t, string s)
{
    int i, j = 0;
    for (i = 0; i < t.length(); i++)
    {
        if (s[j] == t[i])
            j++;
    }
    if (j == s.length())
        return true;
    else
        return false;
}

void code_iske_andar_hai()
{
    string a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    b += c;
    bool z = isSubsequence(a, b);
    reverse(a.begin(), a.end());
    bool y = isSubsequence(a, b);
    if (z and y)
        cout << "both";
    else if (z)
        cout << "forward";
    else if (y)
        cout << "backward";
    else
        cout << "fantasy";
}

signed main()
{
    noTLE;
    // testcase_chalao_bhai
    code_iske_andar_hai();
    return 0;
}