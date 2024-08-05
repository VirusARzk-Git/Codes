// Find efficient way to find phi(n) from 1 to n, where n <= 10^6

#include <bits/stdc++.h>
using namespace std;
int phi[1000001];
#define N 1000000
#define int long long
void sieve()
{
    for (int i = 1; i <= N; i++)
        phi[i] = i;
    for (int i = 2; i * i <= N; i++)
        if (phi[i] == i)
            for (int j = i; j <= N; j += i)
                phi[j] /= i, phi[j] *= (i - 1);
}

signed main()
{

    int n, t;
    cin >> t;
    sieve();
    while (t--)
    {
        cin >> n;
        cout << phi[n] << endl;
    }
    return 0;
}