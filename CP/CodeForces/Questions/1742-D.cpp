// from math import gcd

// for _ in range(int(input())):
//     n = int(input())
//     l = list(map(int,input().strip().split()))[:n]
//     # print(l)
//     hash = [-1]*1001
//     for k in range(len(l)):
//         hash[l[k]]=k

//     # print(hash)
//     final_ans = -1
//     for i in range(1,1001):
//         for j in range(i,1001):
//             if(hash[i]>0 and hash[j]>0):
//                 if (gcd(i,j)==1):
//                     final_ans = max(final_ans,hash[i]+hash[j]+2)
//     print(final_ans)

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
#define array_input_lelo_bhai    \
    ;                            \
    int arr[1001] = {0};         \
    for (int i = 1; i <= n; i++) \
    {                            \
        int temp;                \
        cin >> temp;             \
        arr[temp] = i;           \
    }
// for (int i = 0; i < 1001; i++) \
    // {                              \
    //     arr[i] = -1;               \
    // }                              \
#define array_print_kardo_bhai  \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '

signed main()
{
    noTLE;
    testcase_chalao_bhai
    {
        int n, final_ans = -1;
        cin >> n;
        array_input_lelo_bhai;
        for (int i = 1; i < 1001; i++)
        {
            for (int j = i; j < 1001; j++)
            {
                if (arr[i] > 0 and arr[j] > 0)
                    if (gcd(i, j) == 1)
                        final_ans = max(final_ans, arr[i] + arr[j]);
            }
        }
        cout << final_ans << endl;
    }
    return 0;
}