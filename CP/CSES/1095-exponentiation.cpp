#include <iostream>
using namespace std;

#define int long long
#define mod 1e9 + 7
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
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        pow(a, b, mod);
    }
    return 0;
}