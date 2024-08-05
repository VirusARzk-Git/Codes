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
        array_input_lelo_bhai;
        sort(arr, arr + n);
        int count = 1, max = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
                count++;
            else
            {
                if (max < count)
                    max = count;
                count = 1;
            }
        }
        if (max < count)
            max = count;
        if (max == 1)
            max = 2;
        if (n == 1 || n == 2)
            max = n;
        cout << n - max << endl;
    }
    return 0;
}