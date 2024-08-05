
#include <bits/stdc++.h>

using namespace std;

#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define testcase_chalao_bhai \
    int virus_arzdays;       \
    cin >> virus_arzdays;    \
    while (virus_arzdays--)
#define array_input_lelo_bhai   \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

int code_isdayse_andar_hai()
{
    int n, days, q;
    cin >> n >> days >> q;
    array_input_lelo_bhai;
    int ans = 0;
    int count = 0;
    for (int idx = 0; idx < n; idx++)
    {
        if (arr[idx] <= q)
            count++;
        else
            count = 0;
        if (count >= days)
            ans += (count - days + 1);
    }
    return ans;
}

signed main()
{
    noTLE;
    testcase_chalao_bhai
            cout
        << code_isdayse_andar_hai() << endl;

    return 0;
}