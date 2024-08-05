#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void code()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int a = 0, b = 0;
    for (int i = 1; i < n; i++)
    {
        int fs = b + abs(arr[i] - arr[i - 1]);
        int sc = (i == 1) ? 1e9 : a + abs(arr[i] - arr[i - 2]);
        a = b;
        b = min(fs, sc);
    }
    cout << b;
}

signed main()
{
    code();
    return 0;
}