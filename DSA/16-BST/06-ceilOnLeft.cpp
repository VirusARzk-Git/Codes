#include <iostream>
#include <set>
#include <vector>
using namespace std;

void ceilOnLeft(int *arr, int n)
{
    set<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        auto it = s.upper_bound(arr[i]);
        if (it != s.end())
            ans.push_back(*it);
        else
            ans.push_back(-1);
        s.insert(arr[i]);
    }
    for (int i : ans)
        cout << i << ' ';
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ceilOnLeft(arr, n);
}