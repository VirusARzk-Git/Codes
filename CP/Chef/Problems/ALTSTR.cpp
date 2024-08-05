#include <iostream>
// #include <conio.h>
// #include <stdio.h>
#include <string>
#include <bits/stdc++.h>
// #define ll unsigned long long int
using namespace std;
int main()
{
    // system("cls");
    int t;
    cin >> t;
    while (t--)
    {
        int n, n0 = 0, n1 = 0;
        cin >> n;
        char a[n];
        while (n--)
        {
            cin >> a[n];
            if (a[n] == '0')
                n0++;
            if (a[n] == '1')
                n1++;
        }
        if (n0 < n1)
            n = n0 * 2 + 1;
        if (n0 > n1)
            n = n1 * 2 + 1;
        if (n0 == n1)
            n = n0 * 2;
        cout << n << endl;
    }
    return 0;
}