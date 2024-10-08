#include <iostream>
#include <algorithm>
using namespace std;

int minDiff(int *arr, int n)
{
    sort(arr, arr + n);
    int ans = arr[1] - arr[0];
    for (int i = 2; i < n; i++)
        ans = min(ans, arr[i] - arr[i - 1]);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minDiff(arr, n);
}