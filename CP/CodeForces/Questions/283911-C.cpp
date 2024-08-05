#include <bits/stdc++.h>
using namespace std;

void code(int arr[], int n)
{
    int k;
    cin >> k;
    int low = -1, high = n;
    while (low + 1 < high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] < k)
            low = mid;
        else
            high = mid;
    }
    cout << high+1 << endl;
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