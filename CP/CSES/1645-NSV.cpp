#include <bits/stdc++.h>
using namespace std;
#define int long long

using vi = vector<int>;
#define nnn \
    int n;  \
    cin >> n
#define inArr                    \
    vi arr(n + 1);               \
    for (int i = 1; i <= n; i++) \
    cin >> arr[i]
#define debug(x)     \
    for (auto i : x) \
        cout << i << ' ';

void code()
{
    nnn;
    inArr;
    stack<int> s;
    vi ans(n, 0);
    s.push(1);
    for (int i = 2; i <= n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (s.empty())
            ans[i - 1] = 0;
        else
            ans[i - 1] = s.top();
        s.push(i);
    }
    debug(ans);
}

signed main()
{
    code();
    return 0;
}