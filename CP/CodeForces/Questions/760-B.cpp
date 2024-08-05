#include <bits/stdc++.h>
using namespace std;
#define int long long

int req(int n)
{
    return (n * (n + 1) * 1ull) / 2;
}

int f(int b, int a)
{
    if (b == 0)
        return 0;
    int m = max(0ll, a - b);
    int ans = req(a) - req(m) + max(0ll, b - a);
    // if (a == 4)
    // cout << "Hello " << a << ' ' << b << ' ' << m << ' ' << req(a) << ' ' << req(m) << ' ' << b - a << ' ' << ans << endl;
    return ans;
}

void code()
{
    int n, m, k;
    cin >> n >> m >> k;
    int left = k - 1, right = n - k;
    // cout << left << " " << right << endl;
    int ans = 0;
    int l = 1, r = m;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int min = f(left, mid - 1) + f(right, mid - 1) + mid;
        if (min <= m)
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans;
}

signed main()
{
    code();
    return 0;
}