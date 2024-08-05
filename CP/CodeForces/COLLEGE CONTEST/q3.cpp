/*
Aditya Raj
*/
// #include <string>
#include <bits/stdc++.h>
using namespace std;

#define llnum unsigned long long int

#define fast_virus     \
    int virus_arzk;    \
    cin >> virus_arzk; \
    while (virus_arzk--)
// #define input_array

#define out_array               \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    llnum n, sum = 0, max = 0;
    cin >> n;
    llnum arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    // cout << sum << ' ' << max << ' ';
    sum -= max;
    // cout << sum << ' ' << max<<' ';
    if ((sum + max) % 2 == 0 && sum >= max)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}