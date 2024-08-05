// हर हर महादेव
/*
Aditya Raj
*/
// #include <bits/stdc++.h>
#include <iostream>
// #include <string>
// #include <conio.h>
// #include <stdio.h>
using namespace std;

#define B begin()
#define E end()
#define I iterator
using pii = pair<int, int>;
// using vi = vector<int>;
#define int long long
typedef long double lld;
const int N = 1e7 + 2, M = 1e5 + 10, mod = 1e9 + 7, inf = 4e18, moda = 998244353;
const lld pi = 3.141592653589793;
#define all(x) x.begin(), x.end()
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

void code_iske_andar_hai()
{
    int n;
    cin >> n;
    int hash[10] = {0};
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        hash[t % 10]++;
    }
    if (hash[1] >= 3)
    {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < 10; i++)
        for (int j = i; j < 10; j++)
            for (int k = j; k < 10; k++)
                if ((i + j + k) % 10 == 3)
                {
                    if (i == j and j == k)
                        continue;
                    if (i != j and j != k and i != k and hash[i] and hash[j] and hash[k])
                    {
                        cout << "YES" << endl;
                        return;
                    }
                    int a = min(i, min(j, k));
                    int c = max(i, max(j, k));
                    int b = i + j + k - a - c;
                    if (hash[b] >= 2 and hash[a] and hash[c])
                    {
                        cout << "YES" << endl;
                        return;
                    }
                }
    cout << "NO" << endl;
}

signed main()
{
    noTLE;
    testcase_chalao_bhai
    code_iske_andar_hai();
    return 0;
}