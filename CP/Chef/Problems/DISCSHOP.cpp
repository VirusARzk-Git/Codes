// हर हर महादेव
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
#define array_input_lelo_bhai   \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
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
        int m;
        vi v;
        while (n)
        {
            // m = m * 10 + n % 10;
            v.push_back(n % 10);
            n /= 10;
        }
        // sort(v.begin(), v.end(), reverse = true);
        reverse(v.begin(), v.end());
        int j = v.size() - 1;
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                v.erase(v.begin() + i);
                break;
            }
        }
        int sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            sum = sum * 10 + v[i];
        }
        cout << sum << endl;
    }
    return 0;
}