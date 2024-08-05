/*
Aditya Raj
*/
// #include <string>
#include <bits/stdc++.h>
using namespace std;

#define badka_wala_positive_number unsigned long long int
#define badka_wala_number long long int
#define chotka_wala_number int
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)
#define array_input_lelo_bhai   \
    int arr[n] = {0};           \
    for (int i = 0; i < n; i++) \
    {                           \
        int temp;               \
        cin >> temp;            \
        arr[temp - 1]++;        \
    }
#define array_print_kardo_bhai  \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    testcase_chalao_bhai
    {
        int n, max = 0;
        cin >> n;
        array_input_lelo_bhai for (int i = 0; i < n; i++)
        {
            if (max < arr[i])
                max = arr[i];
        }
        cout << max << endl;
    }
    return 0;
}