#include <iostream>
using namespace std;

int countSubsets(int *arr, int n, int target)
{
    if (n == 0)
        return (target == 0) ? 1 : 0;
    return countSubsets(arr, n - 1, target - arr[n - 1]) + countSubsets(arr, n - 1, target);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cin >> target;
    cout << countSubsets(arr, n, target);
}