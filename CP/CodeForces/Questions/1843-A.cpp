#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nnn \
    int n;  \
    cin >> n

#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)
#define array_input_lelo_bhai   \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

void code_iske_andar_hai()
{
    nnn;
    array_input_lelo_bhai;
    sort(arr, arr + n);
    int ans = 0, i = 0, j = n - 1;
    while (i <= j)
    {
        ans += (arr[j--] - arr[i++]);
    }
    cout << ans << endl;
}

signed main()
{
    noTLE;
    testcase_chalao_bhai
    code_iske_andar_hai();
    return 0;
}