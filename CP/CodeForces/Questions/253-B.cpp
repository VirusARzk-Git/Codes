#include <bits/stdc++.h>
using namespace std;
#define B begin()
#define E end()
using vi = vector<int>;
#define nnn \
    int n;  \
    cin >> n
#define all(x) x.begin(), x.end()
#define inArr                   \
    vi arr(n);                  \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

void code()
{
    nnn;
    inArr;
    sort(all(arr));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(all(arr), arr[i] * 2) - arr.B;
        ans = max(ans, j - i);
    }
    cout << n - ans << endl;
}

signed main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    code();
    return 0;
}