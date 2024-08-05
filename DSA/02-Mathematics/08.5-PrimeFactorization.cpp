#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e7;
vector<int> spf(N, 0);

void SPF()
{
    spf[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            for (int j = i * i; j < N; j += i)
                if (spf[j] == 0)
                    spf[j] = i;
        }
    }
}

signed main()
{
    SPF();
    int n;
    cin >> n;
    vector<int> ans;
    while (n > 1)
    {
        if (spf[n] == n)
        {
            ans.push_back(n);
            break;
        }
        ans.push_back(spf[n]);
        n /= spf[n];
    }
    for (int i : ans)
        cout << i << ' ';
    return 0;
}