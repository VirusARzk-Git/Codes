// GCDMOD       CodeChef

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int power(int a, int n, int d)
{
    // Calculate a^n
    int res = 1;
    while (n)
    {
        if (n % 2)
            res = ((res % d) * (a % d)) % d, n--;
        else
            a = ((a % d) * (a % d)) % d, n /= 2;
    }
    return res;
}

int GCD(int a, int b, int n)
{
    if (a == b)
        return (power(a, n, mod) + power(b, n, mod)) % mod;
    int c = 1;
    int num = abs(a - b);
    for (int i = 1; i <= num; i++)
        if (num % i == 0)
        {
            int tmp = (power(a, n, i) + power(b, n, i)) % i;
            if (!tmp)
                c = max(c, i);

            tmp = (power(a, n, num / i) + power(b, n, num / i)) % (num / i);
            if (!tmp)
                c = max(c, num / i);
        }
    return c % mod;
}

signed main()
{
    int A, B, n, t;
    cin >> t;
    while (t--)
    {
        cin >> A >> B >> n;
        cout << GCD(A, B, n) << endl;
    }
    return 0;
}