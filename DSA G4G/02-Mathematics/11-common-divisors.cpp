
#include <bits/stdc++.h>
using namespace std;

#define int long long
int arr[1000];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void factor(int n)
{
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            arr[i] = 1;
}

int common_divisors(int k, int n)
{
    int hcf = gcd(k, n);
    int cnt = 0;
    for (int i = 1; i * i <= hcf; i++)
    {
        if (hcf % i == 0)
            cnt += 2;
        if (i * i == hcf)
            cnt--;
    }
    return cnt;
}

signed main()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;
        cout << common_divisors(n, k) << endl;
    }
    return 0;
}