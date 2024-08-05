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

#define array_print_kardo_bhai  \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '

signed main()
{
    noTLE;
    testcase_chalao_bhai
    {
        int n, max_index = 0, max = 0;
        cin >> n;
        int arr[n + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            arr[temp]++;
            if (arr[temp] > arr[max_index])
                max_index = temp;
        }
        for (int i = 0; i < n; i += 2)
        {
            if (arr[i] + arr[i + 1] > max)
                max = arr[i] + arr[i + 1];
        }
        if (arr[n] > max)
            max = arr[n];
        
        // if (max_index % 2 == 0 and max_index != n)
        //     max_index = arr[max_index] + arr[max_index + 1];
        // else if (max_index % 2 == 1 and max_index != 1)
        //     max_index = arr[max_index] + arr[max_index - 1];
        // else
        //     max_index = arr[max_index];
        // cout << n - max_index << endl;
        cout << n - max << endl;
    }
    return 0;
}