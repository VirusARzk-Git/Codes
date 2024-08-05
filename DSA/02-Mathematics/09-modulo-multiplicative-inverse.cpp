/*
m is prime
    and 
a and m are co-prime
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int power(int a, int n, int m)
{
    // Calculate a^n
    int res = 1;
    while (n)
    {
        if (n % 2)
            res = (res * a) % m, n--;
        else
            a = (a * a) % m, n /= 2;
    }
    return res;
}

signed main()
{
    int t, a, b, m;
    cin >> t;
    while (t--)
    {
        cin >> a >> m;
        cout << "(a^ -1) % m = " << power(a, m - 2, m) << endl;
    }
    return 0;
}