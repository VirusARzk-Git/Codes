#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
using vi = vector<int>;

bool good(vi arr, int t, int mid)
{
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        cnt += mid / arr[i];
        if (cnt >= t)
            return true;
    }
    return false;
}

void code()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = LLONG_MAX;
    int l = *min_element(all(arr)), r = *max_element(all(arr)) * t;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (good(arr, t, mid))
            ans = min(ans, mid), r = mid - 1;
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