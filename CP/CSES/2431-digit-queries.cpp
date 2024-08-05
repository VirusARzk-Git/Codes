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

#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define tCases  \
    int tcc;    \
    cin >> tcc; \
    while (tcc--)

void code()
{
    int k;
    cin >> k;
    if (k < 10)
    {
        cout << k << endl;
        return;
    }
    int n = 1;
    while (k > 9 * myPow(10, n - 1) * n)
    {
        k -= 9 * myPow(10, n - 1) * n;
        n++;
    }
    int d = (k - 1) % n;

    int ans = myPow(10, n - 1) + (k - 1) / n;

    string s = to_string(ans);
    cout << s[d] << endl;
}

signed main()
{
    noTLE;

    tCases
    code();
    return 0;
}