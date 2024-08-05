#include <bits/stdc++.h>
using namespace std;
#define int long long

void code()
{
    int n;
    cin >> n;
    int x = (n * n - 1) / 2;
    int l = 1, r = n * n, ans;
    while (l <= r)
    {
        int mid = (l + r) / 2, cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += min(mid / i, n);
        if (cnt > x)
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans;
}

signed main()
{
    code();
    return 0;
}