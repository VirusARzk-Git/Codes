// /*
// Aditya Raj
// */

// #include <bits/stdc++.h>
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

// signed main()
// {
//     noTLE;
//     testcase_chalao_bhai
//     {
//         int n, temp_c = 0, count = 0;
//         cin >> n;
//         string arr;
//         cin >> arr;
//         for (int i = 1; i < n; i++)
//         {
//             if (arr[i] == arr[i - 1])
//                 temp_c++;
//             else
//             {
//                 count += temp_c;
//                 temp_c = 0;
//             }
//         }
//         count += temp_c;
//         cout << count << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, j, step = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int j = 1; j < n; j++)
            if (s[j] == s[j - 1])
                step++;
        cout << step << endl;
    }
    return 0;
}