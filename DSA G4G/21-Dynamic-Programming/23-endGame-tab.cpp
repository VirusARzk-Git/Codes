#include <iostream>
using namespace std;

int endGame(int *arr, int n)
{
    int dp[n][n];
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << endGame(arr, n);
}