#include <iostream>
using namespace std;
int maxSumOf_k_Elements(int *arr, int n, int k)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    int ans = sum;
    for (int i = k; i < n; i++)
        sum += (arr[i] - arr[i - k]), ans = max(sum, ans);
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxSumOf_k_Elements(arr, n, k);
}