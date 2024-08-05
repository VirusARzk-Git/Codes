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

void code()
{
    nnn;
    inArr;
    int ans = INT_MAX;
    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                sum += arr[j];
            else
                sum -= arr[j];
        }
        ans = min(ans, abs(sum));
    }
    cout << ans;
}

signed main()
{
    code();
    return 0;
}