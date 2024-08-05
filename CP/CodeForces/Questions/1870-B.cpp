#include <bits/stdc++.h>
using namespace std;
#define int long long

using vi = vector<int>;
#define tCases  \
    int tcc;    \
    cin >> tcc; \
    while (tcc--)

void code()
{
    int n, m, r = 0, mn = 0, mx = 0;
    cin >> n >> m;
    vi a(n), b(m);
    for (int &i : a)        cin >> i;
    for (int &i : b)        cin >> i;
    for (int i : b)         r |= i;
    for (int i : a)         mn ^= i, mx ^= (r | i);
    if (n & 1)              cout << mn << ' ' << mx << endl;
        else                cout << mx << ' ' << mn << endl;
}

signed main()
{
    tCases
    code();
    return 0;
}