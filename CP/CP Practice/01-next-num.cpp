/*
Coded By Aditya Raj -> VirusARzk

In this problem, we are given an element N.
We need to find the next greater number
with the same set of digits.

We need to find the smallest number
with the same digit
which is greater than N.

N = 92534
Output -> 92543

N = 934905
Output -> 934950
*/

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define llnum unsigned long long int

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    llnum n;
    cin >> n;
    llnum m = n;
    int a = m % 10, b;
    int c = 1;
    m /= 10;
    while (m)
    {
        b = m % 10;
        m /= 10;
        c++;
        if (b < a)
            break;
        a = b;
    }
    // llnum d = pow(10, c);
    llnum e = pow(10, c - 2);
    m = (m * 100 + a * 10 + b) * e + n % e;
    cout << m << endl;

    return 0;
}
