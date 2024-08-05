#include <iostream>
using namespace std;

int mChain(int *arr, int i, int j)
{
    if (i + 1 == j)
        return 0;
    int res = INT_MAX;
    for (int k = i + 1; k < j; k++)
        res = min(res, mChain(arr, i, k) + mChain(arr, k, j) + arr[i] * arr[j] * arr[k]);
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << mChain(arr, 0, n - 1);
}