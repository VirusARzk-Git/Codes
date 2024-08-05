#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> PSE(int *arr, int n)
{
    vector<int> v;

    stack<int> s;
    s.push(0);
    v.push_back(-1);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        int pse = s.empty() ? -1 : s.top();
        v.push_back(pse);
        s.push(i);
    }
    return v;
}

vector<int> NSE(int *arr, int n)
{
    vector<int> v;

    stack<int> s;
    s.push(n - 1);
    v.push_back(n);

    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        int nse = s.empty() ? n : s.top();
        v.push_back(nse);
        s.push(i);
    }
    reverse(v.begin(), v.end());
    return v;
}

void largestAreaHistogram(int *arr, int n)
{
    vector<int> nse = NSE(arr, n);
    vector<int> pse = PSE(arr, n);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        curr += (i - pse[i] - 1) * arr[i];
        curr += (nse[i] - i - 1) * arr[i];
        ans = max(ans, curr);
    }

    cout << ans << endl;
}

int largestRecAreaHistogram(int *arr, int n) // efficient implementation
{
    stack<int> s;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            int tp = s.top();
            s.pop();
            int curr = arr[tp] * (s.empty() ? i : (i - s.top() - 1));
            res = max(res, curr);
        }
        s.push(i);
    }

    while (!s.empty())
    {
        int tp = s.top();
        s.pop();
        int curr = arr[tp] * (s.empty() ? n : (n - s.top() - 1));
        res = max(res, curr);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << largestRecAreaHistogram(arr, n);

    return 0;
}