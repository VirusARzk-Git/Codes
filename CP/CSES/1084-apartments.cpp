#include <bits/stdc++.h>
using namespace std;

#define int long long
using vi = vector<int>;
#define all(x) x.begin(), x.end()

void code()
{
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(all(a));
    sort(all(b));
    int ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (abs(a[i] - b[j]) <= k)
        {
            ans++;
            i++;
            j++;
        }
        else if (a[i] < b[j])
            i++;
        else
            j++;
    }
    cout << ans;
}

signed main()
{
    code();
    return 0;
}