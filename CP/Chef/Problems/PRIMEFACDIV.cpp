
#include <bits/stdc++.h>
using namespace std;

#define int long long unsigned
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)

void solve(int a, int b)
{
    int flag = 1, k, p;
    while (b != 1)
    {
        k = gcd(a, b);
        p = b;
        b /= k;
        if (k == 1)
        {
            cout << "NO";
            flag = 0;
            break;
        }
    }
    if (flag)
        cout << "YES";
    cout << endl;
}

signed main()
{
    testcase_chalao_bhai
    {
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}