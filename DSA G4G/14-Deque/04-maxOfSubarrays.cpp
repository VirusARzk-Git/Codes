#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// Maximum in all subarrays of size k

vector<int> printMaxK(int *arr, int n, int k)
{
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    for (int i = k; i < n; i++)
    {
        ans.push_back(arr[dq.front()]);
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    ans.push_back(arr[dq.front()]);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *arr;
    arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    vector<int> ans = printMaxK(arr, n, k);
    for (auto i : ans)
        cout << i << ' ';
}