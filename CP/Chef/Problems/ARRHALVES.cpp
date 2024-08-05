// हर हर महादेव
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
        vi a, b;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (temp > n)
                a.push_back(i);
        }
        for (int i = n; i < 2 * n; i++)
        {
            int temp;
            cin >> temp;
            if (temp <= n)
                b.push_back(i);
        }
        reverse(b.begin(), b.end());
        int sum = 0;
        for (int i = 0; i < a.size(); i++)
        {
            sum += b[i] - a[i];
        }
        cout << sum << endl;
    }
    return 0;
}