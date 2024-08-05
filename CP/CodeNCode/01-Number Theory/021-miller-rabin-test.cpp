#include <bits/stdc++.h>
using namespace std;

#define int long long
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)

int mulmod(int a, int b, int c)
{
    int x = 0, y = a % c;
    while (b > 0)
    {
        if (b % 2)
            x = (x + y) % c;
        y = (y * 2LL) % c;
        b /= 2;
    }
    return x % c;
}

int binPower(int a, int n, int mod)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
            res = mulmod(res, a, mod);
        n >>= 1;
        a = mulmod(a, a, mod);
    }
    return res % mod;
}

int check_composite(int n, int a, int d, int s)
{
    int x = binPower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++)
    {
        x = x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool MillerRabin(int n)
{
    if (n < 2)
        return false;

    int r = 0;
    int d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

signed main()
{
    noTLE;
    testcase_chalao_bhai
    {
        int n;
        cin >> n;
        if (MillerRabin(n))
            cout << "Prime" << endl;
        else
            cout << "Not Prime" << endl;
    }
    return 0;
}