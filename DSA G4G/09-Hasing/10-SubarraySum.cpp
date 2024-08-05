#include <iostream>
#include <unordered_map>
using namespace std;

int LongestSubarraySum(int *arr, int n, int target)
{
    unordered_map<int, int> m;
    int preSum = 0, res = -1;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        if (preSum == target)
            res = i + 1;
        if (m.count(preSum))
            res = max(res, i - m[preSum]);
        else
            m.insert({preSum, i});
    }
    return res;
}

// Longest Subarray with equal 0s and 1s
// Convert all 0 to -1 and find longest subarray with Zero Sum

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cin >> target;
    cout << LongestSubarraySum(arr, n, target);
}