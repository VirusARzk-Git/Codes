#include <iostream>
using namespace std;

int extendedEuclid(int a, int b, int &x, int &y)
{
    if (b == 0) // Base Case
    {
        x = 1;
        y = 0;
        return a;
    }
    int gcd = extendedEuclid(b, a % b, x, y);
    int x1 = y, y1 = x - (a / b) * y;
    x = x1, y = y1;
    return gcd;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int x, y;
    int g = extendedEuclid(a, b, x, y);
    cout << g << " " << x << " " << y << endl;
}