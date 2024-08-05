#include <iostream>
using namespace std;

class minHeap
{
    int *arr;
    int size;
    int capacity;

public:
    minHeap(int c)
    {
        arr = new int[c];
        size = 0;
        capacity = c;
    }

    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int parent(int i) { return (i - 1) / 2; }

    void insert(int x)
    {
        if (size == capacity)
            return;
        arr[size++] = x;
        for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i];)
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void minHeapify(int i)
    {
        int lt = left(i), rt = right(i);
        int smallest = i;
        if (lt < size && arr[lt] < arr[i])
            smallest = lt;
        if (rt < size && arr[rt] < arr[smallest])
            smallest = rt;
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    int extractMin()
    {
        if (size == 0)
            return INT_MIN;
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        minHeapify(0);
        return arr[size];
    }

    void decreaseKey(int i, int x)
    {
        arr[i] = x;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void buildHeap()
    {
        for (int i = (size - 2) / 2; i >= 0; i--)
            minHeapify(i);
    }
};

class maxHeap
{

    int *arr;
    int size;
    int capacity;

public:
    maxHeap(int c)
    {
        arr = new int[c];
        size = 0;
        capacity = c;
    }

    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int parent(int i) { return (i - 1) / 2; }

    void maxHeapify(int i)
    {
        int largest = i, lt = left(i), rt = right(i);
        if (lt < size && arr[lt] > arr[largest])
            largest = lt;
        if (rt < size && arr[rt] > arr[largest])
            largest = rt;
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            maxHeapify(largest);
        }
    }
};

int main()
{
}