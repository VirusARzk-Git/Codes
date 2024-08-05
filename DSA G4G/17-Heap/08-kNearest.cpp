#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kNearest(int *arr, int n, int x, int k)
{
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++)
        pq.emplace(x - arr[i], i);
    for (int i = k; i < n; i++)
    {
        int a = abs(x - arr[i]);
        if (pq.top().first > a)
        {
            pq.pop();
            pq.emplace(a, i);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        auto e = pq.top().second;
        ans.push_back(arr[e]);
        pq.pop();
    }
    return ans;
}

int main()
{
    int n, x, k;
    cin >> n >> x >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> res = kNearest(arr, n, x, k);
    for (int i : res)
        cout << i << ' ';
}