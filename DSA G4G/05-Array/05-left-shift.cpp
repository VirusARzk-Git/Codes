#include <bits/stdc++.h>
using namespace std;

void reverse(int *arr, int low, int high)
{
    while (low < high)
    {
        int swap = arr[low];
        arr[low++] = arr[high];
        arr[high--] = swap;
    }
}

void leftRotate(int *arr, int n, int d)
{
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}

signed main()
{
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    leftRotate(arr, n, d);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    return 0;
}