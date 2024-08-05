#include <bits/stdc++.h>
using namespace std;

#define int long long
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
    int n;
    cin >> n;
    array_input_lelo_bhai;
    int xoxo = 0;
    for (int i = 0; i < n; i++)
        xoxo += arr[i];
    xoxo <<= 1;
    cout << xoxo << endl;
}

signed main()
{
    testcase_chalao_bhai code_iske_andar_hai();
    return 0;
}
