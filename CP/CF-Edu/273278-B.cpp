#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
const int N = 1e5;

int n;
vi arr, bitt(8 * N, 0), lazy(8 * N, 0);

int leftt(int i) { return i * 2 + 1; }
int rightt(int i) { return i * 2 + 2; }
int middle(int l, int r) { return (l + r) / 2; }
int operate(int a, int b) { return a + b; }
void recalculate(int i) { bitt[i] = operate(bitt[leftt(i)], bitt[rightt(i)]); }

void build(int lx = 0, int rx = n - 1, int x = 0)
{
    if (lx == rx)
        bitt[x] = arr[lx];
    else
    {
        int m = middle(lx, rx);
        build(lx, m, leftt(x));
        build(m + 1, rx, rightt(x));
        recalculate(x);
    }
}

void flip(int i, int x = 0, int lx = 0, int rx = n - 1)
{
    if (lx == rx)
    {
        bitt[x] = 1 - bitt[x];
        return;
    }
    int m = (lx + rx) / 2;
    if (i <= m)
        flip(i, 2 * x + 1, lx, m);
    else
        flip(i, 2 * x + 2, m + 1, rx);
    recalculate(x);
}

int idx(int k, int x = 0, int lx = 0, int rx = n - 1)
{
    if (lx == rx)
        return lx;
    int m = (lx + rx) / 2;
    int left = bitt[2 * x + 1];
    if (k < left)
        return idx(k, 2 * x + 1, lx, m);
    else
        return idx(k - left, 2 * x + 2, m + 1, rx);
}

signed main()
{
    cin >> n;
    int q;
    cin >> q;
    arr.resize(n);
    for (int &i : arr)
        cin >> i;
    build();
    // for (int i = 0; i < 4 * n; i++)
    //     cout << bitt[i] << ' ';
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i;
            cin >> i;
            flip(i);
        }
        else
        {
            int k;
            cin >> k;
            cout << idx(k) << endl;
        }
    }
    // for (int i = 0; i < 4 * n; i++)
    //     cout << bitt[i] << ' ';
    // for (int i = 0; i < 4 * n; i++)
    //     cout << lazy[i] << ' ';
    return 0;
}