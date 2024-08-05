#include <bits/stdc++.h>
using namespace std;

#define int long long
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)

void code_iske_andar_hai()
{
    int a, b;
    cin >> a;
    cin >> b;
    if (b < 2 * a)
        cout << -1 << " " << -1 << endl;
    else
        cout << a << " " << 2 * a << endl;
}

signed main()
{
    testcase_chalao_bhai code_iske_andar_hai();
    return 0;
}