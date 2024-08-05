#include <iostream>
using namespace std;
int countAndMerge(int *arr, int low, int mid, int high)
{
    int i, j, k, arrCopy[100];
    i = low;
    j = mid + 1;
    k = low;
    int res = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
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
            res += (mid + 1 - low - i);
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
    return res;
}

int countInv(int *arr, int low, int high)
{
    int res = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        res += countInv(arr, low, mid);
        res += countInv(arr, mid + 1, high);
        res += countAndMerge(arr, low, mid, high);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << countInv(arr, 0, n - 1);
}