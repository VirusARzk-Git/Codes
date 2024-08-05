#include <iostream>
using namespace std;

int Rbsearch(int *arr, int val, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == val)
        return mid;
    if (arr[mid] > val)
        return Rbsearch(arr, val, low, mid - 1);
    return Rbsearch(arr, val, mid + 1, high);
}

int main()
{
    int n, val;
    cin >> n >> val;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << Rbsearch(arr, val, 0, n - 1);
}