#include <iostream>
using namespace std;

#define int long long

void pow(int a, int n)
{
    // Calculate a^n
    int res = 1;
    while (n)
    {
        if (n % 2)
            res *= a, n--;
        else
            a *= a, n /= 2;
    }
    cout << res << endl;
}

// Modular Exponentiation

void pow(int a, int n, int p)
{
    // Calculate a^n % p
    int res = 1;
    while (n)
    {
        if (n % 2)
            res = (res * a) % p, n--;
        else
            a = (a * a) % p, n /= 2;
    }
    cout << res << endl;
}

signed main()
{
    int a, b;
    cin >> a >> b;
    pow(a, b);
    return 0;
}