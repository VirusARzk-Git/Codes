#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> PGE(int *arr, int n)
{
    vector<int> v;

    stack<int> s;
    s.push(arr[0]);
    v.push_back(-1);

    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();
        int pge = s.empty() ? -1 : s.top();
        v.push_back(pge);
        s.push(arr[i]);
    }

    return v;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> v = PGE(arr, n);

    for (auto i : v)
        cout << i << ' ';
}