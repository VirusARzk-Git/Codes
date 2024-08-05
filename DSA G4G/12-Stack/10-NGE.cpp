#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> NGE(int *arr, int n)
{
    vector<int> v;

    stack<int> s;
    s.push(arr[n - 1]);
    v.push_back(-1);

    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();
        int nge = s.empty() ? -1 : s.top();
        v.push_back(nge);
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> v = NGE(arr, n);

    for (auto i : v)
        cout << i << ' ';

    return 0;
}