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

pii code_iske_andar_hai()
{
    int n;
    cin >> n;
    int arr[n], brr[n];
    for (int i = 0; i < 2 * n; i++)
        if (i < n)
            cin >> arr[i];
        else
            cin >> brr[i - n];
    int first = -1, last;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != brr[i] and first == -1)
            first = i;
        if (arr[i] != brr[i])
            last = i;
    }
    // cout << first << " " << last << endl;
    for (int i = first - 1; i >= 0; i--)
        if (brr[i] <= brr[i + 1])
            first--;
        else
            break;
    for (int i = last; i < n - 1; i++)
        if (brr[i] <= brr[i + 1])
            last++;
        else
            break;
    return {first + 1, last + 1};
}

signed main()
{
    noTLE;
    testcase_chalao_bhai
    {
        pii p = code_iske_andar_hai();
        cout << p.first << ' ' << p.second << endl;
    }
    return 0;
}