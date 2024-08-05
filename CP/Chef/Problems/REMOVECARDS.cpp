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
#define big_Num +unsigned long long int
#define big_Num long long int
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)
#define array_input_lelo_bhai    \
    ;                            \
    int arr[10] = {0}, max = 0;  \
    for (int i = 0; i < n; i++)  \
    {                            \
        int temp;                \
        cin >> temp;             \
        arr[temp - 1]++;         \
        if (max < arr[temp - 1]) \
            max = arr[temp - 1]; \
    }                            \
    cout << n - max << endl;
#define array_print_kardo_bhai  \
    ;                           \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << ' ';

int main()
{
    testcase_chalao_bhai
    {
        int n;
        cin>>n;
        array_input_lelo_bhai;
    }
    return 0;
}