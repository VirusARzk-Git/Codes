// Given q queries of type N K, calculate C(N,K) % P , where P > N.

#include <bits/stdc++.h>
using namespace std;
int F[1000001];
#define P 1000000007
int inv(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
            res = (res * 1LL * a) % P, n--;
        else
            a = (a * 1LL * a) % P, n /= 2;
    }
    return res;
}

int C(int N, int K)
{
    if (K > N)
        return 0;
    int res = F[N];
    res = (res * 1LL * inv(F[K], P - 2)) % P;
    res = (res * 1LL * inv(F[N - K], P - 2)) % P;
    return res;
}

void func()
{
    F[0] = F[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        F[i] = (i * 1LL * F[i - 1]) % P;
    }
}

signed main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int N, K;
        // cin >> N >> K >> P;
        cin >> N >> K;
        func();
        cout << C(N, K) << endl;
    }
}