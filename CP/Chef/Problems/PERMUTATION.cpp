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
        int n;
        cin >> n;
        int arr[1001] = {0}, flag = 1, sum = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            sum += temp;
            arr[temp]++;
            if (temp > n)
                flag = 0;
        }
        int count = (n * (n + 1)) / 2;
        count -= sum;
        if (flag)
        {
            for (int i = n; i > 0; i--)
            {
                if (arr[i] > 1)
                {
                    flag = 0;
                    break;
                }
                else if (arr[i] < 1)
                {
                    arr[i - 1] -= ((-1)*arr[i] + 1);
                }
            }
        }
        // cout << arr[0] << arr[1] << arr[2] << arr[3];
        if (!flag)
            count = -1;
        cout << count << endl;
    }
    return 0;
}