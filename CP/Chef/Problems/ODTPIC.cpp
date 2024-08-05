#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("popcnt")
#define int long long

void code()
{
    bitset<4005> bs;
    int n, m, q;
    cin >> n >> m >> q;
    int arr[n], brr[m];
    vector<bitset<4005>> a(n + 1, 0);
    vector<bitset<4005>> b(m + 1, 0);
    bitset<4005> curr1(0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        curr1.flip(arr[i]);
        a[i + 1] = curr1;
    }
    bitset<4005> curr2(0);
    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
        curr2.flip(brr[i]);
        b[i + 1] = curr2;
    }
    while (q--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--, l2--;
        bitset<4005> ans = a[r1] ^ a[l1] ^ b[r2] ^ b[l2];
        cout << ans.count() << endl;
    }
}

signed main()
{
    code();
    return 0;
}