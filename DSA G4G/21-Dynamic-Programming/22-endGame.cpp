#include <iostream>
using namespace std;

int endGame(int *arr, int i, int j, int sum)
{
    if (j == i + 1)
        return max(arr[i], arr[j]);
    return max(sum - endGame(arr, i + 1, j, sum - arr[i]), sum - endGame(arr, i, j - 1, sum - arr[j]));
}

int endGame(int *arr, int i, int j)
{
    if (i + 1 == j)
        return max(arr[i], arr[j]);
    return max(arr[i] + min(endGame(arr, i + 2, j), endGame(arr, i + 1, j - 1)), arr[j] + min(endGame(arr, i + 1, j - 1), endGame(arr, i, j - 2)));
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    cout << endGame(arr, 0, n - 1);
}