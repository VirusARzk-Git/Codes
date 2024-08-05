#include <iostream>
using namespace std;

//  Sort an array with three types of elements
//  Sort an array with 0's 1's and 2's as elements

void partition(int *arr, int n, int a, int b)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] < a)
            swap(arr[low], arr[mid]), low++, mid++;
        else if (arr[mid] <= b)
            mid++;
        else
            swap(arr[high], arr[mid]), high--;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int a, b;
    cin >> a >> b;
    partition(arr, n, a, b);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}