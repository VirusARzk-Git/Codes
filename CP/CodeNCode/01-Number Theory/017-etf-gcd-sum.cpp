
#include <bits/stdc++.h>
using namespace std;

int phi[1000001];
#define NN 1000000
#define int long long

void sieve()
{
    for (int i = 1; i <= NN; i++)
        phi[i] = i;
    for (int i = 2; i * i <= NN; i++)
        if (phi[i] == i)
            for (int j = i; j <= NN; j += i)
                phi[j] /= i, phi[j] *= (i - 1);
}

int getCount(int d, int n)
{
    // cout << phi[n / d] << endl;
    return phi[n / d];
}

signed main()
{
    int q, N;
    cin >> q;
    sieve();
    while (q--)
    {
        cin >> N;
        int res = 0;
        for (int i = 1; i * i <= N; i++)
            if (N % i == 0)
            {
                int d1 = i;
                int d2 = N / i;
                res += d1 * getCount(d1, N);
                if (d1 != d2)
                    res += d2 * getCount(d2, N);
            }
        cout << res << endl;
    }
    return 0;
}