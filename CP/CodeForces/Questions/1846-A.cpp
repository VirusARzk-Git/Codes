
#include <bits/stdc++.h>
using namespace std;

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

int code()
{
    int n;
    int result = 0;
    cin >> n;
    int ht, dis;
    for (int i = 0; i < n; i++)
    {
        cin >> ht >> dis;
        if ((ht - dis) > 0)
            ans++;
    }
    return ans;
}

signed main()
{
    noTLE;
    testcase_chalao_bhai
            cout
        << code_iske_andar_hai() << endl;
    return 0;
}

