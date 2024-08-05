#include <iostream>
using namespace std;

void primeFact(int n)
{
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            ans += (i * i == n) ? 1 : 2;
    }
    cout << ans << endl;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        primeFact(n);
    }
}