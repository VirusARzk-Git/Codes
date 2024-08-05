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
    testcase_chalao_bhai
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string pr = "YES\n";
        if (n == 1)
        {
            cout << pr;
            continue;
        }
        int a = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0' and a == -1 and i % 2 == 1)
            {
                pr = "NO\n";
                break;
            }
            if (s[i] == '0' and a == -1)
                a = i;
            else if (s[i] == '0')
                if ((i - a) % 2 == 0)
                {
                    pr = "NO\n";
                    break;
                }
                else
                    a = i;
        }
        if (a == -1 and n % 2 != 0)
            pr = "NO\n";
        if ((n - a) % 2 == 0)
            pr = "NO\n";
        cout << pr;
    }
    return 0;
}