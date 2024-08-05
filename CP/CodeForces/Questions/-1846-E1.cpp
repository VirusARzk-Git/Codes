#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        bool ok = 0;
        for (int k = 2; k <= 1000 && k < n; k++)
        {
            long long least = k, sum = k;
            for (int x = 2; x <= 20; x++)
            {
                least *= k;
                sum += least;
                if (sum + 1 > n)
                    break;
                if (sum + 1 == n)
                {
                    ok = 1;
                    break;
                }
            }
            if (ok)
                break;
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}