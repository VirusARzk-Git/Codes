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

void code_iske_andar_hai()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n - 1, 0);
    v.push_back(1);
    int current = 1;
    for (int i = n; i < m; i++)
    {
        v.push_back(current);
        current += (v[i] - v[i - n]);
    }
    for (int i = 0; i < m; i++)
        cout << v[i] << ' ';
}

signed main()
{
    noTLE;
    // testcase_chalao_bhai
    code_iske_andar_hai();
    return 0;
}