#include <bits/stdc++.h>
#define ll unsigned long long int
#define fast_tc \
    int t;      \
    cin >> t;   \
    while (t--)
using namespace std;

int main()
{
    int ar[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    fast_tc
    {
        int sum = 0;
        ll a, b;
        cin >> a >> b;
        a += b;
        while (a)
        {
            sum = sum + ar[a % 10];
            a /= 10;
        }
        cout << sum << endl;
    }

    return 0;
}