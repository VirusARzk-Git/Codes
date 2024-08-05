#include <iostream>
using namespace std;

void cycleSort(int *arr, int n)
{
    int writes = 0;
    for (int cs = 0; cs <= n - 2; cs++)
    {
        int item = arr[cs];
        int pos = cs;
        for (int i = cs + 1; i < n; i++)
            if (arr[i] < item)
                pos++;

        if (pos == cs)
            continue;

        while (item == arr[pos])
            pos += 1;

        if (pos != cs)
        {
            swap(item, arr[pos]);
            writes++;
        }

        while (pos != cs)
        {
            pos = cs;

            for (int i = cs + 1; i < n; i++)
                if (arr[i] < item)
                    pos += 1;

            while (item == arr[pos])
                pos += 1;

            if (item != arr[pos])
            {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }

    // Number of memory writes or swaps
    cout << writes << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cycleSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}