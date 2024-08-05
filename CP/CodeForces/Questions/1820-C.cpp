
#include <bits/stdc++.h>
using namespace std;

#define B begin()
#define E end()
#define I iterator
using pii = pair<int, int>;
using vi = vector<int>;
#define int long long
typedef long double lld;
const int N = 1e7 + 2, M = 1e5 + 10, mod = 1e9 + 7, inf = 4e18, moda = 998244353;
const lld pi = 3.141592653589793;
#define all(x) x.begin(), x.end()
// #define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
    // cout << arr[i] << ' '

vi removeDuplicates(vi v)
{
    vi ans;
    ans.push_back(v[0]);
    for (int i = 0; i < v.size(); i++)
        if (v[i] != ans[ans.size() - 1])
            ans.push_back(v[i]);
    // v = ans;
    return ans;
}

bool code_iske_andar_hai()
{
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (n == 1 and v[0] != 0)
        return true;
    vi cp = v;
    sort(all(cp));
    cp = removeDuplicates(cp);

    // for (auto i : cp)
    // cout << i << ' ';

    int ans = -1;
    for (int i = 0; i < cp.size(); i++)
        if (cp[i] != i)
        {
            ans = i;
            break;
        }
    if (ans == -1)
        ans = cp[cp.size() - 1];
    int cnt = count(all(v), ans + 1);
    // cout << ans << endl;
    // cout << ans + 1 << endl;
    // cout << cnt << endl;

    if (cnt == 0)
    {
        if (ans == *max_element(all(cp)))
            if (cp.size() < v.size())
                return true;
            else
                return false;
        else
            return true;
    }
    else if (cnt == 1)
        return true;
    else
    {
        int first = 0, last = 0;
        for (int i = 0; i < n; i++)
            if (v[i] == ans + 1)
            {
                first = i;
                break;
            }
        for (int i = n - 1; i > 0; i--)
            if (v[i] == ans + 1)
            {
                last = i;
                break;
            }
        if ((last - first - 1) == 0)
            return true;
        for (int i = first; i <= last; i++)
            v[i] = ans;
        vi cp = v;
        sort(all(cp));
        cp = removeDuplicates(cp);
        int ans2 = -1;
        for (int i = 0; i < cp.size(); i++)
            if (cp[i] != i)
            {
                ans2 = i;
                break;
            }
        if (ans2 == -1)
            ans2 = cp[cp.size() - 1] + 1;
        // cout << ans << ' ' << ans2 << endl;

        if (ans2 == ans + 1)
            return true;
        return false;
    }
}

signed main()
{
    // noTLE;
    testcase_chalao_bhai
    {
        if (code_iske_andar_hai())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}