#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void sortK(int *arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i <= k; i++)
        pq.push(arr[i]);
    int index = 0;
    for (int i = k + 1; i < n; i++)
    {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while (!pq.empty())
    {
        arr[index++] = pq.top();
        pq.pop();
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sortK(arr, n, k);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}