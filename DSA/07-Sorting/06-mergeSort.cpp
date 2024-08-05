
#include <iostream>
using namespace std;

void merge(int *arr, int low, int mid, int high)
{
    int i, j, k, arrCopy[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            arrCopy[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            arrCopy[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        arrCopy[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        arrCopy[k] = arr[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
        arr[i] = arrCopy[i];
}

void mergeSort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void input(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    input(arr, n);
    mergeSort(arr, 0, n - 1);
    print(arr, n);
}