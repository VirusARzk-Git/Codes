#include <iostream>
using namespace std;

signed main()
{
    int q, n, i;
    cin >> q;
    while (q--)
    {
        cin >> n >> i;
        int f = 1;
        f <<= i;
        f &= n;
        if (f)
            cout << "Set";
        else
            cout << "Reset";
        cout << endl;
    }
    return 0;
}