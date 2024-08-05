#include <iostream>
using namespace std;

int firstOccurence(int *arr, int n, int val)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == val and (mid == 0 or arr[mid - 1] != val))
            return mid;
        else if (arr[mid] < val)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n, val;
    cin >> n >> val;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << firstOccurence(arr, n, val);
}