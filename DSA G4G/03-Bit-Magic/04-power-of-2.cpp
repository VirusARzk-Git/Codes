#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define loop while (true)

int power_of_two(int n)
{
    if (n == 0)
        return 0;
    return ((n & (n - 1)) == 0);
}

signed main()
{
    loop
    {
        int n;
        cin >> n;
        if (power_of_two(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}