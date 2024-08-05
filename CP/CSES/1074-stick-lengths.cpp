// हर हर महादेव
/*
Aditya Raj
*/
#include <bits/stdc++.h>
using namespace std;

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

void code_iske_andar_hai()
{
    int n;
    cin >> n;
    array_input_lelo_bhai;
    sort(arr, arr + n);
    int j = arr[n / 2];
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += abs(j - arr[i]);
    cout << sum;
}

signed main()
{
    noTLE;
    code_iske_andar_hai();
    return 0;
}