#include <iostream>
using namespace std;
void maxSumSubarray(int *arr, int n)
{
    int maxEnding = arr[0];
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        result = max(result, maxEnding);
    }
    cout << result << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    maxSumSubarray(arr, n);
}