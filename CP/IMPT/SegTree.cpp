#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;
using vi = vector<int>;
#define all(x) x.begin(), x.end()

int bit_ceil(int N)
{
    if (!(N & (N - 1)))
        return N;
    return 0x8000000000000000 >> (__builtin_clzll(N) - 1);
}

struct segmentTree
{
    int size;
    vector<int> sums;
    void init(int n)
    {
        size = bit_ceil(n);
        sums.assign(2 * size, 0);
    }
    void set(int i, int v, int x = 0, int lx = 0, int rx = n - 1)
    {
        if (lx == rx)
        {
            sums[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i <= m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m + 1, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    int sum(int l, int r, int x = 0, int lx = 0, int rx = n - 1)
    {
        if (l > rx || r < lx)
            return 0;
        if (lx >= l && rx <= r)
            return sums[x];
        int m = (lx + rx) / 2;
        int s1 = sum(l, r, 2 * x + 1, lx, m);
        int s2 = sum(l, r, 2 * x + 2, m + 1, rx);
        return s1 + s2;
    }
};

void code()
{
    int m;
    cin >> n >> m;
    segmentTree st;
    st.init(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.set(i, x);
    }

    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r - 1) << endl;
        }
    }
}

signed main()
{
    code();
    return 0;
}