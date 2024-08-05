#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
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
    int count = 0, cc = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == 0)
            count++;
        else if (arr[i] == 1)
            cc++;
    int c = (n + 1) / 2;
    if (count <= c)
        cout << 0 << endl;
    else if (count == n)
        cout << 1 << endl;
    else if (cc + count == n)
        cout << 2 << endl;
    else
        cout << 1 << endl;
}

signed main()
{
    testcase_chalao_bhai
    code_iske_andar_hai();
    return 0;
}