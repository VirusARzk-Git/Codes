// हर हर महादेव
/*
Aditya Raj
*/
#include <iostream>
#include <math.h>
// #include <string>
// #include <conio.h>
// #include <stdio.h>
using namespace std;

#define int long long unsigned int
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
        int n, sum = 0, max = 0, j = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
            if (arr[i] > max)
            {
                max = arr[i];
                j = i;
            }
        }
        double br;
        br = (double)sum / n;
        // cout << br;
        int sum1 = 0, flag = 0;
        double res = 0;
        for (int i = 0; i <= j; i++)
        {
            // int res = 0;
            sum1 += arr[i];
            res = (double)sum1 / (i + 1);
            if (res > br)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << ceil(res) << endl;
        else
            cout << ceil(br) << endl;
    }
    return 0;
}