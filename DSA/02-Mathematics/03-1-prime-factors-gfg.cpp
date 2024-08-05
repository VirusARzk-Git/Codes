#include <iostream>
using namespace std;

void print_Prime_Factors(int n)
{
    if (n == 1)
        return;
    while (!(n % 2))
    {
        cout << 2 << ' ';
        n = n / 2;
    }
    while (!(n % 3))
    {
        cout << 3 << ' ';
        n = n / 3;
    }

    for (int i = 5; i * i <= n; i += 6)
        if (!(n % i))
        {
            cout << i << ' ';
            n = n / i;
        }
        else if (!(n % (i + 2)))
        {
            cout << i + 2 << ' ';
            n = n / (i + 2);
        }
    if (n > 1)
        cout << n;
    cout << endl;
}

#define infinite_loop while (true)
int main()
{
    infinite_loop
    {
        int n;
        cin >> n;
        print_Prime_Factors(n);
    }
}