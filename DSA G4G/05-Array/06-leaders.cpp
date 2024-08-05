#include <bits/stdc++.h>
using namespace std;

void printLeaders(int *arr, int n)
{
    int current_leader = arr[n - 1];
    cout << current_leader << ' ';
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] > current_leader)
        {
            current_leader = arr[i];
            cout << current_leader << ' ';
        }
}

signed main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printLeaders(arr, n);
    return 0;
}