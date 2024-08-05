#include <iostream>
using namespace std;

int power(int x, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
            res = res * x;
        x *= x, n /= 2;
    }
    return res;
}

int pow(int x, int n)
{
    if (!n)
        return 1;
    int temp = pow(x, n / 2);
    temp *= temp;
    if (n % 2)
        return temp * x;
    else
        return temp;
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

#define infinite_loop while (true)

int main()
{
    infinite_loop
    {
        int n, a;
        cin >> n >> a;
        cout << power(n, a) << endl;
    }
}