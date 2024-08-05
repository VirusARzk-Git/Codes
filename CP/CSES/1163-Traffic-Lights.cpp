#include <bits/stdc++.h>
using namespace std;

void code()
{
    int x, n;
    cin >> x >> n;
    set<int> s{0, x};
    multiset<int> m{x};
    while (n--)
    {
        int a;
        cin >> a;
        auto ub = s.upper_bound(a);
        auto lb = ub;
        lb--;
        int old = *ub - *lb;
        m.erase(m.find(old));
        m.insert(*ub - a);
        if (*lb < a)
            m.insert(a - *lb);
        s.insert(a);
        auto mx = m.rbegin();
        cout << *mx << ' ';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    code();
    return 0;
}