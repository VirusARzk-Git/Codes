#include <bits/stdc++.h>
using namespace std;

#define int long long
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)
#define array_input_lelo_bhai    \
    int arr[n + 1];              \
    for (int i = 1; i <= n; i++) \
    cin >> arr[i]

void code_iske_andar_hai()
{
    int n, res = 0;
    cin >> n;
    array_input_lelo_bhai;
    for (int i = 0; i < 32; i++)
    {
        int cntz = 0, cnto = 0;
        for (int j = 1; j <= n; j++)
        {
            if (arr[j] & (1 << i))
                cnto++;
            else
                cntz++;
        }
        int p = cnto * cntz;
        res += p * (1 << i);
    }
    cout << res << endl;
}

signed main()
{
    // testcase_chalao_bhai
    code_iske_andar_hai();
    return 0;
}