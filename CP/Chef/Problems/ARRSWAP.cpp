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

#define array_input_lelo_bhai       \
    int arr[2 * n];                 \
    for (int i = 0; i < 2 * n; i++) \
    cin >> arr[i]

signed main()
{
    noTLE;
    testcase_chalao_bhai
    {
        int n, c = 0;
        cin >> n;
        array_input_lelo_bhai;
        sort(arr, arr + 2 * n);
        int min = arr[n] - arr[0];
        for (int i = 0; i <= n; i++)
        {
            if ((arr[n + i - 1] - arr[i]) < min)
                min = arr[n + i - 1] - arr[i];
        }
        cout << min << endl;
    }
    return 0;
}