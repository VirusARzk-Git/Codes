#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

void code()
{
    int n;
    cin >> n;
    while (!isPrime(++n));
    cout << n << '\n';
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
        code();
    return 0;
}