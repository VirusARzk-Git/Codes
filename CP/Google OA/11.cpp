#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> &arr, int j)
{
    map<int, int> cnt;
    long long totalSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        totalSum += arr[i];
        cnt[totalSum]++;
    }

    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        totalSum -= arr[i];
        if (totalSum % 2)
            continue;
        int half = totalSum / 2;
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; j++)
            cin >> arr[j];
        int maxEqualSums = 0;
        for (int j = 0; j < n; j++)
            maxEqualSums = max(maxEqualSums, helper(arr, j));
        cout << maxEqualSums << "\n";
    }
    return 0;
}