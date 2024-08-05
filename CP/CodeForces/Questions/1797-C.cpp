
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

void code_iske_andar_hai()
{
    int n, m;
    cin >> n >> m;
    int a, b, c;
    cout << "? 1 1\n";
    cout.flush();
    cin >> a;
    if (!a)
    {
        cout << "! 1 1\n";
        cout.flush();
    }
    else
    {
        cout << "? 1 " << min(a + 1, m) << endl;
        cout.flush();
        cin >> b;
        if (!b)
        {
            cout << "! 1 " << min(a + 1, m) << endl;
            cout.flush();
        }
        else
        {
            cout << "? " << min(n, a + 1) << ' ' << 1 << endl;
            cout.flush();
            cin >> c;
            if (c == 0)
            {
                cout << "! " << min(n, a + 1) << ' ' << 1 << endl;
                cout.flush();
            }
            else
            {
                cout << "! " << b + 1 << ' ' << c + 1 << endl;
                cout.flush();
            }
        }
    }
}

signed main()
{
    noTLE;
    testcase_chalao_bhai
    code_iske_andar_hai();
    return 0;
}