#include <iostream>

#define int long long unsigned
const int MOD = 1e9 + 7;

// Modular Exponentiation
int pow(int a, int n, int p)
{
    if (a == 0 and n == 0)
        return 1;
    int res = 1;
    while (n)
    {
        if (n % 2)
            res = (res * a) % p;
        a = (a * a) % p;
        n /= 2;
    }
    return res % p;
}

signed main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        int x = pow(b, c, MOD - 1);
        std::cout << pow(a, x, MOD) << '\n';
    }
    return 0;
}
