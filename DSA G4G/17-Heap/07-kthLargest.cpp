#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargest(int *arr, int n, int k)
{
    priority_queue<int> pq(arr, arr + n);
    for (int i = 1; i < k; i++)
        pq.pop();
    return pq.top();
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << kthLargest(arr, n, k);
}