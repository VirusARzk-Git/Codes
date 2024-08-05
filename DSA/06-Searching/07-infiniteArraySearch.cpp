#include <iostream>
using namespace std;

int bsearch(int *arr, int low, int high, int val)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == val)
            return mid;
        else if (arr[mid] > val)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int searchInAnInfiniteSizedArray(int *arr, int val)
{
    if (arr[0] == val)
        return 0;
    int i = 1;
    while (arr[i] < val)
        i *= 2;
    if (arr[i] == val)
        return i;
    return bsearch(arr, i / 2 + 1, i - 1, val);
}

int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << searchInAnInfiniteSizedArray(arr, val);
}