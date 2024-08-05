#include <iostream>
using namespace std;

void sortBinary(int *arr, int n)
{
    int i = -1, j = n;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] == 0);
        do
        {
            j--;
        } while (arr[j] == 1);
        if (i >= j)
            return;
        swap(arr[i], arr[j]);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sortBinary(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}