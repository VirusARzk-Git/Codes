#include <iostream>
using namespace std;

//  Sort an array with three types of elements
//  Sort an array with 0's 1's and 2's as elements

void sort3(int *arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
            swap(arr[low], arr[mid]), low++, mid++;
        else if (arr[mid] == 1)
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
    sort3(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}