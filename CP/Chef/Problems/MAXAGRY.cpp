/*
Aditya Raj
*/
#include <bits/stdc++.h>
// #include <string>
// #include <conio.h>
// #include <stdio.h>
using namespace std;

#define int long long
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)

signed main()
{
    noTLE;
    testcase_chalao_bhai
    {
        int n, k;
        cin >> n >> k;
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        if (k >= n / 2)
        {
            cout << (n * (n - 1)) / 2 << endl;
            continue;
        }
        int a = (n * (n - 1)) / 2 - ((n - k) * (n - k - 1)) / 2 + (n - 2 * k) * k + (k * (k - 1)) / 2;
        cout << a << endl;
    }
    return 0;
}