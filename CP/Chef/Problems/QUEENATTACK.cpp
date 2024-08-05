#include <iostream>
// #include <conio.h>
// #include <stdio.h>
// #include <string>
#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, a, b, c = 0, min;
        cin >> n >> a >> b;
        c = 3 * (n - 1);
        if(a>n/2)   a=n-a+1;
        if(b>n/2)   b=n-b+1;
        if (a < b)
            min = a;
        else
            min = b;
        c = c + (min * 2) - 2;
        cout << c << endl;
    }
    return 0;
}