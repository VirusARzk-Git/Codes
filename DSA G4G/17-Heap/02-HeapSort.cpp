#include <iostream>
using namespace std;

int left(int i) { return (2 * i + 1); }
int right(int i) { return (2 * i + 2); }
int parent(int i) { return (i - 1) / 2; }

void maxHeapify(int *arr, int n, int i)
{
    int largest = i, lt = left(i), rt = right(i);
    if (lt < n && arr[lt] > arr[largest])
        largest = lt;
    if (rt < n && arr[rt] > arr[largest])
        largest = rt;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildHeap(int *arr, int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void heapSort(int *arr, int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    heapSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}