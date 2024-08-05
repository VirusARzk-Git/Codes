#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int mypow(int x, int y, int p = 1e9 + 7)
{
    if (y < 0)
    {
        return 0;
    }
    int res = 1;

    while (y > 0)
    {
        if (y % 2 == 1)
        {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res % p;
}

#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)

#define modi 1000000007
void code_iske_andar_hai()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int lst = 0;
    int rst = 0;
    int ans = 0;
    int l4 = 0, r4 = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '4')
            r4++;
        else if (s[i] == '*')
            rst++;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '4')
            r4--;
        else if (s[i] == '*')
            rst--;
        if (s[i] == '0' || s[i] == '*')
        {
            int l = 0, r = 0;
            // cout << l4 << lst << rst << r4 << endl;
            if (lst)
                l = (l + (lst * mypow(2ll, lst - 1, modi) * 1ll) % modi) % modi;
            if (l4)
                l = (l + (l4 * mypow(2ll, lst, modi) * 1ll) % modi) % modi;
            if (rst)
                r = (r + (rst * mypow(2ll, rst - 1, modi) * 1ll) % modi) % modi;
            if (r4)
                r = (r + (r4 * mypow(2ll, rst, modi) * 1ll) % modi) % modi;
            ans = (ans + (l * r * 1ll) % modi) % modi;
        }
        if (s[i] == '4')
            l4++;
        else if (s[i] == '*')
            lst++;
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