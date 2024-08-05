#include <iostream>
using namespace std;

void print_divisors(int n, int k = 1)
{
    if (k * k > n)
    {
        return;
    }
    if (n % k == 0)
    {
        cout << k << ' ';
        print_divisors(n, k + 1);
        if (n / k != k)
            cout << n / k << ' ';
    }
    else
        print_divisors(n, k + 1);
}

void printDivisors(int n) // GFG - Still Error
{
    int i;
    for (i = 1; i * i < n; i++)
        if (n % i == 0)
            cout << i << ' ';
    for (; i > 0; i--)
        if (n % i == 0)
            cout << n / i << ' ';
    cout << endl;
}

#define infinite_loop while (true)
int main()
{
    infinite_loop
    {
        int n;
        cin >> n;
        print_divisors(n);
        cout << endl;
    }
}