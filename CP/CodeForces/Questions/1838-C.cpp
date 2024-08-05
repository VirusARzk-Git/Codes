
#include <bits/stdc++.h>
using namespace std;

#define B begin()
#define E end()
#define I iterator
using pii = pair<int, int>;
using vi = vector<int>;
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
    int virus_arzval;        \
    cin >> virus_arzval;     \
    while (virus_arzval--)
#define array_input_lelo_bhai   \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define array_print_valardo_bhai \
    for (int i = 0; i < n; i++)  \
    cout << arr[i] << ' '

void code_isvale_andar_hai()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    if (m % 2 == 0)
    {
        int val = 1;
        int mid;
        if (n % 2)
            mid = (n / 2) + 1;
        else
            mid = (n / 2);
        for (int i = 0; i < mid; i++)
        {
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = val;
                val++;
            }
            val += m;
        }
        val = m + 1;

        for (int i = mid; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = val;
                val++;
            }
            val += m;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << arr[i][j] << ' ';
            cout << endl;
        }
    }
    else
    {
        int val = 1;
        int mid;
        if (n % 2)
            mid = (n / 2) + 1;
        else
            mid = (n / 2);
        for (int i = 0; i < mid; i++)
        {
            for (int j = 0; j < m; j++)
            {
                arr[mid - i - 1][j] = val;
                val++;
            }
            val += m;
        }
        val = m + 1;

        for (int i = mid; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                arr[n - 1 - i + mid][j] = val;
                val++;
            }
            val += m;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << arr[i][j] << ' ';
            cout << endl;
        }
    }
    cout << endl;
}

signed main()
{
    noTLE;
    testcase_chalao_bhai
    code_isvale_andar_hai();
    return 0;
}