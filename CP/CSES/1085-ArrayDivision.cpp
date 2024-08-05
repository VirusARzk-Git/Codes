#include <bits/stdc++.h>
using namespace std;

#define int long long

using vi = vector<int>;
#define all(x) x.begin(), x.end()
#define inArr                   \
    vi arr(n);                  \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

int k;

bool good(vi arr, int mid)
{
    int sum = 0, cnt = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (sum + arr[i] > mid)
        {
            cnt++;
            sum = arr[i];
        }
        else
            sum += arr[i];
    }
    return cnt <= k;
}

void code()
{
    int n;
    cin >> n;
    cin >> k;
    inArr;
    int l = *max_element(all(arr)), r = accumulate(all(arr), 0LL), ans;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (good(arr, mid))
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