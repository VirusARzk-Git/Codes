#include <bits/stdc++.h>
using namespace std;

#define int long long

using vi = vector<int>;
#define inArr                   \
    vi arr(n);                  \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

void code()
{
    int n;
    cin >> n;
    inArr;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        auto it = s.upper_bound(arr[i]);
        if (it != s.end())
            s.erase(it);
        s.insert(arr[i]);
    }
    cout << s.size();
}

signed main()
{
    code();
    return 0;
}