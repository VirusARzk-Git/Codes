#include <bits/stdc++.h>
using namespace std;

#define int long long unsigned

void code()
{
    int n, m;
    cin >> n >> m;
    int x;
    cin >> x;
    cout << ((n + x - 1) / x) * ((m + x - 1) / x);
}

signed main()
{
    code();
}