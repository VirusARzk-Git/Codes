#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
#define nnn \
    int n;  \
    cin >> n
#define inArr                   \
    vi arr(n);                  \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

bool good(vi arr, int k, int mid)
{
    int n = arr.size();
    int ans = 0;
    for (int i = n / 2; i < n; i++)
        ans += max(0LL, mid - arr[i]);
    return ans <= k;
}

void code()
{
    nnn;
    int k;
    cin >> k;
    inArr;
    sort(arr.begin(), arr.end());
    int low = arr[n / 2], high = arr[n / 2] + k, ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (good(arr, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << endl;
}

signed main()
{
    code();
    return 0;
}