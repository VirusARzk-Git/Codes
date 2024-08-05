// Given an unsorted array of non-negative integers.
// Find if there is a subarray with the given sum.

#include <iostream>
using namespace std;
int main()
{
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int currSum = arr[0];

    int start = 0, end = 1;
    for (end = 1; end < n; end++)
    {
        while (currSum > sum and start < end - 1)
            currSum -= arr[start++];
        if (currSum == sum)
        {
            cout << "YES";
            return 0;
        }
        if (end < n)
            currSum += arr[end];
    }
    if (currSum == sum)
        cout << "YES";
    else
        cout << "NO";
}