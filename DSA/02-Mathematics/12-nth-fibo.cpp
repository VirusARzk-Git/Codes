#include <bits/stdc++.h>
using namespace std;
#define int long long
int add(int a, int b, int m) { return (a + b) % m; }
int sub(int a, int b, int m) { return (a % m - b % m + m) % m; }
int mul(int a, int b, int m) { return ((a % m) * (b % m) * 1ll) % m; }
const int mod = 1e9 + 7;

pair<int, int> fib(int n)
{
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = mul(p.first, sub(mul(p.second, 2, mod), p.first, mod), mod);
    int d = add(mul(p.first, p.first, mod), mul(p.second, p.second, mod), mod);
    if (n & 1)
        return {d, add(c, d, mod)};
    else
        return {c, d};
}

signed main()
{
    int n;
    cin >> n;
    cout << fib(n).first << endl;
    return 0;
}