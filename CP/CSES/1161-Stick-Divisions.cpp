#include <bits/stdc++.h>
using namespace std;

#define int long long

using vi = vector<int>;
#define all(x) x.begin(), x.end()

#define inArr                   \
    vi arr(n);                  \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

void code()
{
    int x, n;
    cin >> x;
    cin >> n;
    inArr;
    multiset<int>s(all(arr));
    int ans = 0;
    while (s.size() > 1)
    {
        int a = *s.begin();
        s.erase(s.begin());
        int b = *s.begin();
        s.erase(s.begin());
        ans += (a + b);
        s.insert(a + b);
    }
    cout << ans;
}

signed main()
{
    code();
    return 0;
}