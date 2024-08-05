#include <bits/stdc++.h>
using namespace std;

int B(int arr[], int n)
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
    return l + 1;
}

int C(int arr[], int n)
{
    int k;
    cin >> k;
    int l = -1, h = n;
    while (l + 1 < h)
    {
        int mid = (h + l) / 2;
        if (arr[mid] < k)
            l = mid;
        else
            h = mid;
    }
    return h + 1;
}

void code(int arr[], int n)
{
    int l = C(arr, n);
    int r = B(arr, n);
    cout << r - l + 1 << ' ';
}

signed main()
{
    int n, q;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cin >> q;
    while (q--)
        code(arr, n);
    return 0;
}