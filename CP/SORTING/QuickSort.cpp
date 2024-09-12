#include <iostream>
using namespace std;

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l;
    for (int j = l; j < r; ++j)
        if (arr[j] < pivot)
            swap(arr[i++], arr[j]);
    swap(arr[i], arr[r]);
    return i;
}

void QuickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        QuickSort(arr, l, pi - 1);
        QuickSort(arr, pi + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    QuickSort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}