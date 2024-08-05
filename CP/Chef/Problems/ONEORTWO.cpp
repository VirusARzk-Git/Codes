#include <bits/stdc++.h>
using namespace std;

#define int long long
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)

void code_iske_andar_hai()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
        if (a % 2)
            cout << "CHEF";
        else
            cout << "CHEFINA";
    else if (a > b + 1)
        cout << "CHEF";
    else if (b > a + 1)
        cout << "CHEFINA";
    else if (abs(a - b) == 1)
    {
        if (min(a, b) % 2)
            cout << "CHEF";
        else
            cout << "CHEFINA";
    }
    cout << endl;
}

signed main()
{
    noTLE;
    testcase_chalao_bhai
    code_iske_andar_hai();
    return 0;
}