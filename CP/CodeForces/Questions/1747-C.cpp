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
#define int long long unsigned
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)
#define array_input_lelo_bhai   \
    ;                           \
    int arr[n], min = -1;       \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> arr[i];          \
        if (min > arr[i])       \
            min = arr[i];       \
    }
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
        array_input_lelo_bhai;
        if (min == arr[0])
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }
    return 0;
}