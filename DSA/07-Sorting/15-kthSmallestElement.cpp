#include <iostream>
using namespace std;

int lPartition(int *arr, int low, int high, int p = 0)
{
    // swap(arr[p], arr[high]);
    int pivot = arr[high]; // Always Last
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
        if (arr[j] <= pivot)
            i++, swap(arr[j], arr[i]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int kthSmallestElement(int *arr, int n, int k)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int p = lPartition(arr, l, r);
        if (p == k - 1)
            return arr[p];
        else if (p > k - 1)
            r = p - 1;
        else
            l = p + 1;
    }
    return -1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << kthSmallestElement(arr, n, k);
}