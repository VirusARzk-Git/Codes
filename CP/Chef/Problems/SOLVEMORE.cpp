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
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)
#define array_input_lelo_bhai(a, n) \
    int a[n];                       \
    for (int i = 0; i < n; i++)     \
    cin >> a[i]
#define array_print_kardo_bhai(a, n) \
    for (int i = 0; i < n; i++)      \
    cout << arr[i] << ' '

void code_iske_andar_hai()
{
    int n, k, sum = 0, cnt = 0, mx = LONG_LONG_MIN;
    cin >> n >> k;
    array_input_lelo_bhai(arr, n);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second;
        v[i].first = arr[i] + v[i].second;
    }
    int i;
    sort(v.begin(), v.end());
    for (i = 0; i < n; i++)
        if (sum + v[i].first <= k)
        {
            sum += v[i].first, cnt++;
            mx = max(mx, v[i].second);
            // cout << sum << endl;
        }
        else
            break;
    // sum -= mx;
    // if (i < n and sum + v[i].first <= k)
    //     cnt++;
    // else
    // {
    //     sum += mx;
    for (; i < n; i++)
        if (sum + v[i].first - v[i].second <= k)
        {
            cnt++;
            break;
        }
    // }
    cout << cnt << endl;
}

signed main()
{
    testcase_chalao_bhai
    code_iske_andar_hai();
    return 0;
}