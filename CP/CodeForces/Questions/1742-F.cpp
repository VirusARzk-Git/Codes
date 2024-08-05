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
#define testcase_dalao_bhai \
    int virus_arzk;         \
    cin >> virus_arzk;      \
    while (virus_arzk--)
#define array_input_lelo_bhai   \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define array_print_kardo_bhai  \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '

void solve_this_question()
{
    int q;
    cin >> q;
    int s[26] = {1};
    int t[26] = {1};
    int sl = 1, tl = 1;
    while (q--)
    {
        int d, k;
        string x;
        cin >> d >> k >> x;
        if (d == 1)
        {
            sl += x.length() * k;
            for (int i = 0; i < x.length(); i++)
                s[x[i] - 'a'] += k;
        }
        else
        {
            tl += x.length() * k;
            for (int i = 0; i < x.length(); i++)
                t[x[i] - 'a'] += k;
        }
        if (tl != t[0])
            cout << "YES\n";
        else if (s[0] == sl and sl < tl)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

signed main()
{
    noTLE;
    testcase_dalao_bhai
    {
        solve_this_question();
    }
    return 0;
}