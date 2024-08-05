// हर हर महादेव
/*
Aditya Raj
*/
#include <bits/stdc++.h>
#include <math.h>
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
#define array_input_lelo_bhai   \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define array_print_kardo_bhai  \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '

signed main()
{
    noTLE;
    testcase_chalao_bhai
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int result = a * a + b * b;
        int res = c * c + d * d;
        if (result < res)
            cout << "BOB\n";
        else if (result > res)
            cout << "ALEX\n";
        else
            cout << "EQUAL\n";
    }
    return 0;
}