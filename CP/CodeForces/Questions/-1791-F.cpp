// // हर हर महादेव
// /*
// Aditya Raj
// */
// #include <bits/stdc++.h>
// // #include <string>
// // #include <conio.h>
// // #include <stdio.h>
// using namespace std;

// #define B begin()
// #define E end()
// #define I iterator
// using pii = pair<int, int>;
// using vi = vector<int>;
// #define int long long
// #define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define testcase_chalao_bhai \
//     int virus_arzk;          \
//     cin >> virus_arzk;       \
//     while (virus_arzk--)
// #define array_input_lelo_bhai   \
//     int arr[n];                 \
//     for (int i = 0; i < n; i++) \
//     cin >> arr[i]
// #define array_print_kardo_bhai  \
//     for (int i = 0; i < n; i++) \
//     cout << arr[i] << ' '

// signed main()
// {
//     noTLE;
//     testcase_chalao_bhai
//     {
//         int n, q;
//         cin >> n >> q;
//         array_input_lelo_bhai;
//         while (q--)
//         {
//             int qq;
//             cin >> qq;
//             if (qq == 1)
//             {
//                 int l, r;
//                 cin >> l >> r;
//                 for (int j = l - 1; j < r; j++)
//                 {
//                     int m = arr[j];
//                     if (m < 10)
//                         continue;
//                     int s = 0;
//                     while (m)
//                     {
//                         s += m % 10;
//                         m /= 10;
//                     }
//                     arr[j] = s;
//                 }
//             }
//             else if (qq == 2)
//             {
//                 int x;
//                 cin >> x;
//                 cout << arr[x - 1] << endl;
//             }
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
#define int long long
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

int f(int n)
{
    if (n < 10)
        return n;
    return n % 10 + f(n / 10);
}

signed main()
{
    testcase_chalao_bhai
    {
        int n, q;
        cin >> n >> q;
        array_input_lelo_bhai;
        int qqq[n] = {0};
        while (q--)
        {
            int qq;
            cin >> qq;
            if (qq == 1)
            {
                int l, r;
                cin >> l >> r;
                for (int j = l - 1; j < r; j++)
                    if (arr[j] > 9)
                        qqq[j]++;
                // {
                //     int m = arr[j];
                //     if (m < 10)
                //         continue;
                //     int s = 0;
                //     while (m)
                //     {
                //         s += m % 10;
                //         m /= 10;
                //     }
                //     arr[j] = s;
                // }
            }
            else if (qq == 2)
            {
                int x;
                cin >> x;
                x--;
                for (int k = 0; k < qqq[x] and arr[x] > 9; k++)
                    arr[x] = f(arr[x]);
                qqq[x] = 0;
                cout << arr[x] << endl;
            }
        }
    }
    return 0;
}
