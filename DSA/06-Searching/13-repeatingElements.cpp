#include <bits/stdc++.h>
using namespace std;

// Array Size >= 2
// Only one element repeats (Any number of times)
// All the elements from 0 to max(arr) are present

int findRepeating(int *arr, int n)
{
    int slow = arr[0], fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findRepeating(arr, n);
    return 0;
}