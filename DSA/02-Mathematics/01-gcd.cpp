#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

#define infinite_loop while (true)
int main()
{
    infinite_loop
    {
        int a, b;
        cin >> a >> b;
        cout << "GCD = " << gcd(a, b) << endl;
        cout << "LCM = " << lcm(a, b) << endl;
    }
}