#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

signed main()
{
    while (1)
    {
        int n;
        cin >> n;
        cout << n << " is " << (isPrime(n) ? "Prime" : "Not Prime") << endl;
    }
}