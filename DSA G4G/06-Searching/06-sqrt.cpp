#include <bits/stdc++.h>
using namespace std;

int sqRootFloor(int x)
{
    int low = 0, high = x, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int mSq = mid * mid; // Middle Square
        if (mSq == x)
            return mid;
        else if (mSq > x)
            high = mid - 1;
        else
            low = mid + 1, ans = mid;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << sqRootFloor(n) << endl;
}