#include <bits/stdc++.h>
using namespace std;

void code(int arr[], int n)
{
    int k;
    cin >> k;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
        {
            cout << "YES" << endl;
            return;
        }
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "NO" << endl;
}

signed main()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (q--)
    {
        code(arr, n);
    }
    return 0;
}