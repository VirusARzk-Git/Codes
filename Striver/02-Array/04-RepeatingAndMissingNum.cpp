#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int xr = 0;
    for (int i = 0; i < a.size(); i++)
        xr = xr ^ (i + 1), xr = xr ^ a[i];
    // cout << xr << endl;
    int y = 0;
    for (int i = 0; i < a.size();)
    {
        if ((a[i] & xr) == xr)
            y ^= a[i];
        i++;
        if ((i & xr) == xr)
            y ^= i;
    }
    for (int i : a)
        if (i == y)
            return {y, xr ^ y};
    return {xr ^ y, y};
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    v = findMissingRepeatingNumbers(v);
    for (int i : v)
        cout << i << " ";
}