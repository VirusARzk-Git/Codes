#include <iostream>
using namespace std;

int hoare_partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        // returns the index of the element to the left of the pivot element
        swap(arr[i], arr[j]);
    }
}

void qSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int p = hoare_partition(arr, low, high);
        qSort(arr, low, p);
        qSort(arr, p + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    qSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}