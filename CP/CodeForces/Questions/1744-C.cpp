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
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        // s += s;
        int flag = -1;
        int j = 0;
        int m = 0;
        if (c == 'g')
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i < 2 * n; i++)
        {
            if (s[i % n] == c and flag != 1)
            {
                flag = 1;
                j = i;
            }
            if (s[i % n] == 'g' and flag == 1)
            {
                flag = 0;
                m = max(m, i - j);
            }
        }
        cout << m << endl;
    }
    return 0;
}