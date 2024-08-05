#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestChainPairs(vector<pair<int, int>> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<int> lis(n, 1);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[j].second < arr[i].first)
                lis[i] = max(lis[i], lis[j] + 1);
    return *max_element(lis.begin(), lis.end());
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    cout << longestChainPairs(v);
}