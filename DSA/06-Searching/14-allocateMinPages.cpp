#include <bits/stdc++.h>
using namespace std;

bool isFeasible(vector<int> arr, int n, int k, int ans)
{
    int req = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > ans)
            req++, sum = arr[i];
        else
            sum += arr[i];
    }
    return (req <= k);
}

int allocateMinPages(vector<int> arr, int n, int k)
{
    int mx = *max_element(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int low = mx, high = sum, res = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isFeasible(arr, n, k, mid))
            res = mid, high = mid - 1;
        else
            low = mid + 1;
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << allocateMinPages(arr, n, k);
    return 0;
}