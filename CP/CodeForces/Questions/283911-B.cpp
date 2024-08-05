#include <bits/stdc++.h>
using namespace std;

void code(int arr[], int n)
{
    int k;
    cin >> k;
    int l = -1, r = n;
    while (l + 1 < r)
    {
        int m = (r + l) / 2;
        if (arr[m] <= k)
            l = m;
        else
            r = m;
    }
    cout << l + 1 << endl;
}

signed main()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (q--)
        code(arr, n);
    return 0;
}