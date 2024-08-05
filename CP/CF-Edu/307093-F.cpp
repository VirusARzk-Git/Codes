#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;

deque<int> mx, mn;

void add(int x)
{
    while (!mx.empty() && mx.back() < x)
        mx.pop_back();
    mx.push_back(x);
    while (!mn.empty() && mn.back() > x)
        mn.pop_back();
    mn.push_back(x);
}

void remove(int x)
{
    if (mx.front() == x)
        mx.pop_front();
    if (mn.front() == x)
        mn.pop_front();
}

int k;
bool good() { return (mx.front() - mn.front() <= k); }

void code()
{
    int n;
    cin >> n >> k;
    vi arr(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int start = 0, end = 0;
    while (end < n)
    {
        add(arr[end]);
        while (!good())
        {
            remove(arr[start]);
            start++;
        }
        ans += end - start + 1;
        end++;
    }
    cout << ans;
}

signed main()
{
    code();
    return 0;
}