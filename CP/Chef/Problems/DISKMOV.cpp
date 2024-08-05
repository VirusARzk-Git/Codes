/*
Aditya Raj
*/
#include <bits/stdc++.h>
// #include <string>
// #include <conio.h>
// #include <stdio.h>
using namespace std;

// #define B begin()
// #define E end()
// #define I iterator
// using pii = pair<ll, ll>;
// using vi = vector<ll>;
#define ll unsigned long long int
#define testcase_chalao_bhai \
    ll virus_arzk;           \
    cin >> virus_arzk;       \
    while (virus_arzk--)
#define array_input_lelo_bhai         \
    ll arr[n], hash[2 * n + 1] = {0}; \
    for (ll i = 0; i < n; i++)        \
    {                                 \
        cin >> arr[i];                \
        hash[arr[i]]++;               \
        if (arr[i] > max)             \
            max = arr[i];             \
    }

int main()
{
    testcase_chalao_bhai
    {
        ll n, k, max = 0, ans = 0;
        cin >> n >> k;
        ll p = k;
        array_input_lelo_bhai;

        ll ans1 = 0, ans2 = 0;
        for (ll i = 1; i <= 2 * n; i++)
        {
            if (i >= max)
                break;
            if (hash[i] == 0)
            {

                ans1 = ans1 + max - i;
                k--;
            }
            if (k <= 0)
                break;
        }

        max = 2 * n;
        k = p - 1;
        for (ll i = 1; i <= 2 * n; i++)
        {
            if (k <= 0)
                break;
            if (hash[i] == 0)
            {
                ans2 = ans2 + max - i;
                k--;
            }
        }
        cout << ((ans1 > ans2) ? ans1 : ans2) << endl;
    }
    return 0;
}