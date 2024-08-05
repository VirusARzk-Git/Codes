#include <bits/stdc++.h>
using namespace std;

#define int long long

using vi = vector<int>;
#define all(x) x.begin(), x.end()
#define inArr                   \
    vi arr(n);                  \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
multiset<int> s;

void code()
{
    int n;
    cin >> n;
    inArr;
    for (int i = 0; i < n; i++)
    {
        auto it = s.lower_bound(arr[i]);
        if (it == s.end())
            s.insert(arr[i]);
        else
            s.erase(it), s.insert(arr[i]);
    }
    cout << s.size() << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    code();
    return 0;
}