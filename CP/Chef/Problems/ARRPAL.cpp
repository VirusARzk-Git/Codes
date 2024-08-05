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
#define big_Num unsigned long long int
// #define big_Num long long int
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

int main()
{
    testcase_chalao_bhai
    {
        int n, flag = 1;
        cin >> n;
        array_input_lelo_bhai;
        for (int i = 0; i < n / 2; i++)
        {
            if (arr[i] != arr[n - i - 1])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cout << 0 << endl;
            continue;
        }
        flag = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (arr[i] > arr[n - i - 1])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            cout << -1 << endl;
            continue;
        }
        flag = 0;
        int i;
        for (i = 0; i < n / 2; i++)
        {
            if (arr[i] == arr[n - i - 1])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            for (i++; i < n / 2; i++)
            {
                if (arr[i] != arr[n - i - 1])
                {
                    flag = -1;
                    break;
                }
            }
            if (flag == -1)
            {
                cout << -1 << endl;
                continue;
            }
        }
        flag = arr[n - 1] - arr[0];
        for (i = 0; i < n / 2; i++)
        {
            if (arr[i] + flag < arr[n - i - 1])
            {
                flag = -1;
                break;
            }
            else
                flag = arr[n - i - 1] - arr[i];
        }
        if (flag == -1)
        {
            cout << -1 << endl;
            continue;
        }
        cout << arr[n - 1] - arr[0] << endl;
    }
    return 0;
}