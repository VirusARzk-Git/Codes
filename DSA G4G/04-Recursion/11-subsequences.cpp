#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printSubsequences(vector<vector<int>> &ans, int *arr, int n, vector<int> a, int i = 0)
{
    if (i == n)
    {
        ans.push_back(a);
        return;
    }
    printSubsequences(ans, arr, n, a, i + 1);
    a.push_back(arr[i]);
    printSubsequences(ans, arr, n, a, i + 1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> ans;
    vector<int> v;
    printSubsequences(ans, arr, n, v);

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto v : ans)
    {
        for (auto i : v)
            cout << i << ' ';
        cout << endl;
    }
}