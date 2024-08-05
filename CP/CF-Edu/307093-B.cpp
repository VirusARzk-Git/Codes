#include <bits/stdc++.h>
using namespace std;

#define int long long

void code()
{
    int n;
    cin >> n;
    int s;
    cin >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int start = 0, end = 0, ans = INT_MAX, currSum = 0;
    while (start <= end && end < n)
    {
        currSum += arr[end];
        while (currSum - arr[start] >= s)
            currSum -= arr[start++];
        if(currSum >= s)
        ans = min(ans, end - start + 1);
        end++;
    }
    if (ans == INT_MAX)
        ans = -1;
    cout << ans;
}

signed main()
{
    code();
    return 0;
}