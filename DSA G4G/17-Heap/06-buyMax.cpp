#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maxItems(int *prices, int n, int money)
{
    priority_queue<int, vector<int>, greater<int>> pq(prices, prices + n);
    int ans = 0;
    while (1)
        if (pq.empty() == false && pq.top() < money)
            ans++, money -= pq.top(), pq.pop();
        else
            break;
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxItems(arr, n, m);
}