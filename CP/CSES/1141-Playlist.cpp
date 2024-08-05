#include <bits/stdc++.h>
using namespace std;

#define int long long

using vi = vector<int>;
#define nnn \
    int n;  \
    cin >> n
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define inArr                   \
    vi arr(n);                  \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
void code()
{
    nnn;
    inArr;
    set<int> s;
    int ans = 0, start = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i]) != s.end())
            while (arr[start++] != arr[i])
                s.erase(arr[start - 1]);
        else
            s.insert(arr[i]);
        // cout << start << ' ' << i << ' ' << s.size() << endl;
        ans = max(ans, (int)s.size());
    }
    cout << ans;
}

signed main()
{
    code();
    return 0;
}