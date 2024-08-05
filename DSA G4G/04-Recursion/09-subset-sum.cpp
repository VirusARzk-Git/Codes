#include <iostream>
using namespace std;

int count(int *arr, int n, int sum)
{
    if (n == 0)
        return (sum == 0) ? 1 : 0;
    return count(arr, n - 1, sum) + count(arr, n - 1, sum - arr[n - 1]);
}

int main()
{
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << count(arr, n, sum) << endl;
}