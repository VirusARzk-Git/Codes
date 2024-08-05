#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
const int N = 1e5;

int n;
vi arr, seg(8 * N, 0), lazy(8 * N, 0);

int leftt(int i) { return i * 2 + 1; }
int rightt(int i) { return i * 2 + 2; }
int middle(int l, int r) { return (l + r) / 2; }
int operate(int a, int b) { return a + b; }
void recalculate(int i) { seg[i] = operate(seg[leftt(i)], seg[rightt(i)]); }

void build(int low = 0, int high = n - 1, int ind = 0)
{
    if (low == high)
        seg[ind] = arr[low];
    else
    {
        int m = middle(low, high);
        build(low, m, leftt(ind));
        build(m + 1, high, rightt(ind));
        recalculate(ind);
    }
}

void updateQuery(int l, int r, int val, int low = 0, int high = n - 1, int ind = 0)
{
    if (lazy[ind])
    {
        seg[ind] += (high - low + 1) * lazy[ind];
        if (low != high)
            lazy[leftt(ind)] += lazy[ind], lazy[rightt(ind)] += lazy[ind];
        lazy[ind] = 0;
    }

    if (low > high || l > high || r < low)
        return;

    if (low >= l && high <= r)
    {
        seg[ind] += (high - low + 1) * val;
        if (low != high)
            lazy[leftt(ind)] += val, lazy[rightt(ind)] += val;
        return;
    }

    int mid = middle(low, high);
    updateQuery(l, r, val, low, mid, leftt(ind));
    updateQuery(l, r, val, mid + 1, high, rightt(ind));
    recalculate(ind);
}

int getValue(int l, int r, int low = 0, int high = n - 1, int ind = 0)
{
    if (lazy[ind])
    {
        seg[ind] += (high - low + 1) * lazy[ind];
        if (low != high)
            lazy[leftt(ind)] += lazy[ind], lazy[rightt(ind)] += lazy[ind];
        lazy[ind] = 0;
    }

    if (low > high || l > high || r < low)
        return 0;

    if (low >= l && high <= r)
        return seg[ind];
    int ans = 0;
    int mid = middle(low, high);
    if (l <= mid)
        ans = operate(ans, getValue(l, r, low, mid, leftt(ind)));
    if (r > mid)
        ans = operate(ans, getValue(l, r, mid + 1, high, rightt(ind)));
    return ans;
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
    while (q--)
    {
        int qtype = 2;
        cin >> qtype;
        if (qtype == 2)
        {
            int l, r;
            cin >> l;
            l--, r--;
            cout << getValue(l, l) << endl;
        }
        else
        {
            int l, r, a;
            cin >> l >> r >> a;
            l--, r--;
            updateQuery(l, r, a);
        }
    }
    // for (int i = 0; i < 4 * n; i++)
    //     cout << seg[i] << ' ';
    // for (int i = 0; i < 4 * n; i++)
    //     cout << lazy[i] << ' ';
    return 0;
}