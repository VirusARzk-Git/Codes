/*
Koko loves to eat bananas. There are n piles of bananas, the i-th pile has piles[i] bananas.
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k.
Each hour, she chooses some pile of bananas and eats k bananas from that pile.
If the pile has less than k bananas, she eats all of them instead
 and will not eat any more bananas during this hour.

Koko likes to eat sLly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

*/

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
#define int long long

int f(int k, vector<int> &arr)
{
    int sum = 0;
    for (int q : arr)
        sum += (q + k - 1) / k;
    return sum;
}

int minEatingSpeed(vector<int> &arr, int h)
{
    int L = 1;
    int H = *max_element(arr.begin(), arr.end());
    int ans = H;
    // cout << f(30, arr);
    while (L <= H)
    {
        // cout << ans << endl;
        int mid = (L + H) / 2;
        if (f(mid, arr) <= h)
            ans = min(ans, mid), H = mid - 1;
        else
            L = mid + 1;
    }
    return ans;
}

signed main()
{
    int n, h;
    cin >> n >> h;
    vector<int> arr;
    while (n--)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    cout << minEatingSpeed(arr, h);
    return 0;
}