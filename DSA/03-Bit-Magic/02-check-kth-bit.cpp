#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define loop while (true)

void k_th_bit(int n, int k)
{
    if (n & 1 << k)
        cout << "Set";
    else
        cout << "Reset";
}

void k_th_bit(int n, int k)
{
    if (n >> k & 1)
        cout << "Set";
    else
        cout << "Reset";
}

signed main()
{
    loop
    {
        int n, k;
        cin >> n >> k;
        k_th_bit(n, k);
        cout << endl;
    }
    return 0;
}