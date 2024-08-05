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

void code_iske_andar_hai()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
        for (int i = 1; i < n; i += 2)
        {
            cout << i + 1 << ' ' << i << ' ';
        }
    if (n % 2)
        cout << -1;
    cout << '\n';
}

signed main()
{
    noTLE;
    testcase_chalao_bhai
    code_iske_andar_hai();
    return 0;
}