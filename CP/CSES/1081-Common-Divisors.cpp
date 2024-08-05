#include <bits/stdc++.h>
using namespace std;

int code()
{
    unordered_map<int, int> freq;
    unordered_map<int, int> multiplies;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }

    int ans = 1;

    for (auto e : freq)
    {
        for (int i = 1; i * i <= e.first; i++)
        {
            if (e.first % i == 0)
            {
                multiplies[i] += e.second;
                if (i * i != e.first)
                    multiplies[e.first / i] += e.second;
            }
        }
    }
    for (auto e : multiplies)
    {
        if (e.second > 1)
            ans = max(ans, e.first);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << code();
}
