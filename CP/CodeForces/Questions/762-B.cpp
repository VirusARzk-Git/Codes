#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()

void code()
{
    int a, b, c;
    cin >> a >> b >> c;
    int n;
    cin >> n;
    vector<int> u, p;
    while (n--)
    {
        string s;
        int aa;
        cin >> aa >> s;
        if (s == "USB")
            u.push_back(aa);
        else
            p.push_back(aa);
    }
    sort(all(u));
    sort(all(p));
    int i = 0, j = 0, ans = 0;
    while (a-- && i < u.size())
        ans += u[i++];
    while (b-- && j < p.size())
        ans += p[j++];
    while (c-- && (i < u.size() || j < p.size()))
    {
        if (i == u.size())
            ans += p[j++];
        else if (j == p.size())
            ans += u[i++];
        else if (u[i] < p[j])
            ans += u[i++];
        else
            ans += p[j++];
    }
    cout << i + j << ' ' << ans;
}

signed main()
{
    code();
    return 0;
}