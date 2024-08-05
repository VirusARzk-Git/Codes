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
#define debug(x) \
    // for (auto i : x)      \
    //     cout << i << ' '; \
    // cout << endl;

void NSE(vi arr, vi &nse)
{
    int n = arr.size();
    stack<int> s;
    nse[n - 1] = n;
    s.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (s.empty())
            nse[i] = n;
        else
            nse[i] = s.top();
        s.push(i);
    }
    debug(nse);
}

void PSE(vi arr, vi &pse)
{
    int n = arr.size();
    stack<int> s;
    pse[0] = -1;
    s.push(0);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (s.empty())
            pse[i] = -1;
        else
            pse[i] = s.top();
        s.push(i);
    }
    debug(pse);
}

void code()
{
    nnn;
    inArr;
    vector<int> nse(n), pse(n);
    PSE(arr, pse);
    NSE(arr, nse);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, arr[i] * (nse[i] - pse[i] - 1));
    cout << ans;
}

void code2()
{
    nnn;
    inArr;
    stack<int> s;
    int ans = 0;
    arr.push_back(0);
    for (int i = 0; i <= n; i++)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            int h = arr[s.top()];
            s.pop();
            int w;
            if (s.empty())
                w = i;
            else
                w = i - s.top() - 1;
            ans = max(ans, h * w);
        }
        s.push(i);
    }

    cout << ans;
}

signed main()
{
    code2();
    return 0;
}