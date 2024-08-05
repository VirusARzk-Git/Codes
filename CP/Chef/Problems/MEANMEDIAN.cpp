#include <bits/stdc++.h>
#define fast_tc \
    int t;      \
    cin >> t;   \
    while (t--)
using namespace std;

int main()
{
    fast_tc
    {
        int x, y;
        cin >> x >> y;
        if (x < y)
            cout << y << ' ' << y + 1 << ' ' << 3 * x - y * 2 - 1 << endl;
        else if (x > y)
            cout << y << ' ' << y - 1 << ' ' << 3 * x - 2 * y + 1 << endl;
        else
            cout << y << ' ' << y << ' ' << y << endl;
    }
    return 0;
}