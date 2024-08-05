/*
Aditya Raj
*/
#include <bits/stdc++.h>
// #include <string>
// #include <conio.h>
// #include <stdio.h>
using namespace std;

#define B begin()
#define E end()
#define I iterator
using pii = pair<int, int>;
using vi = vector<int>;
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
    string col = "ROYGBIV";
    int n;
    cin >> n;
    while (n >= 7)
    {
        cout << col;
        n -= 7;
    }
    // if (n == 1)
    //     cout << col[3];
    // else
    string s = "GBIV";
    for (int i = 0; i < n; i++)
        cout << s[i % 4];
    return 0;
}