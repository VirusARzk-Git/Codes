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
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)
#define array_input_lelo_bhai   \
    big_Num arr[n];             \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define array_print_kardo_bhai  \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '

int main()
{
    testcase_chalao_bhai
    {
        // int n;
        // cin >> n;
        char v[8][8];
        // string temp;
        // cin >> temp;
        // cin >> temp;
        // getch();
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                cin >> v[i][j];
                // cout << v[i][j];
            }

        // for (int i = 0; i < 8; i++)
        //     for (int j = 0; j < 8; j++)
        //         cout << v[i][j];

        int flag = 0;
        for (int j = 0; j < 8; j++)
        {
            int flag2 = flag;
            for (int i = 0; i < 8; i++)
            {
                if (v[j][i] != 'R')
                {
                    flag = (flag + 1);
                    break;
                }
            }
            if (flag2 == flag)
            {
                flag = 2;
                cout << "R\n";
                break;
            }
        }
        if (flag == 2)
            continue;
        flag = 0;
        // for (int i = 0; i < 8; i++)
        // {
        //     int flag2 = flag;
        //     for (auto it : v)
        //         if (it[i] != 'B')
        //         {
        //             flag = (flag + 1) % 2;
        //             break;
        //         }
        //     if (flag2 == flag)
        //     {
        //         cout << "B\n";
        //         break;
        //     }
        // }
        // int flag = 0;
        for (int j = 0; j < 8; j++)
        {
            int flag2 = flag;
            for (int i = 0; i < 8; i++)
            {
                if (v[i][j] != 'B')
                {
                    flag = (flag + 1);
                    break;
                }
            }
            if (flag2 == flag)
            {
                flag = 2;
                cout << "B\n";
                break;
            }
        }
    }
    return 0;
}