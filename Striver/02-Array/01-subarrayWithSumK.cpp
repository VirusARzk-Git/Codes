#include <iostream>
#include <unordered_map>
using namespace std;

#define int long long

int subarraySumK(int *arr, int n, int k)
{
    unordered_map<int, int> m;
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
            ans = max(ans, i + 1);
        int rem = sum - k;
        if (m[rem])
            ans = max(ans, i - m[rem] + 1);
        if (m[sum] == 0)
            m[sum] = i + 1;
    }
    return ans;
}

signed main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << subarraySumK(arr, n, k);
    return 0;
}