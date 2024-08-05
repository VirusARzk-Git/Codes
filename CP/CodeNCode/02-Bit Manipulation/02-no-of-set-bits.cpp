#include <iostream>
using namespace std;
/*
signed main()
{
    int q, n, i;
    cin >> q;
    while (q--)
    {
        cin >> n;
        int cnt = 0;
        while (n)
        {
            if (n & 1)
                cnt++;
            n >>= 1;
        }
        cout << cnt << endl;
    }
    return 0;
}
*/
signed main()
{
    int q, n, i;
    cin >> q;
    while (q--)
    {
        cin >> n;
        int cnt = 0;
        while (n)
        {
            cnt++, n &= (n - 1);
        }
        cout << cnt << endl;
    }
    return 0;
}