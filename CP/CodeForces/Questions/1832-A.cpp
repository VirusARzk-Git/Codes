
#include <iostream>
#include <vector>
using namespace std;

#define int long long
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
    string s;
    cin >> s;
    int c = 0;
    bool hashh[26] = {0};
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] == s[s.length() - 1 - i] and !hashh[s[i] - 'a'])
            c++, hashh[s[i] - 'a'] = 1;
    }
    if (c > 1)
        yes;
    else
        no;
}

signed main()
{
    noTLE;
    testcase_chalao_bhai
    code_iske_andar_hai();
    return 0;
}