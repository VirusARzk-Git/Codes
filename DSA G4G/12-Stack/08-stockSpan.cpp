#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printSpan(int *arr, int n)
{
    vector<int> v;

    stack<int> s;
    s.push(0);
    v.push_back(1);

    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
            s.pop();
        int span = s.empty() ? i + 1 : i - s.top();
        v.push_back(span);
        s.push(i);
    }

    for (auto i : v)
        cout << i << ' ';
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printSpan(arr, n);
}