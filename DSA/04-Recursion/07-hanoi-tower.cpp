#include <iostream>
using namespace std;

void TOH(int n, int a = 1, int b = 2, int c = 3)
{
    if (n == 0)
        return;
    TOH(n - 1, a, c, b);
    // cout << "Disc moved from " << a << " to " << c << endl;
    cout << "Disc " << n << " moved from " << a << " to " << c << endl;
    TOH(n - 1, b, a, c);
}

int main()
{
    int n;
    cin >> n;
    TOH(n);
}