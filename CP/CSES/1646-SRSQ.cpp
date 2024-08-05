#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
const int N = 1e5;

int n;
vi arr, tree(8 * N, 0);

int leftt(int i) { return i * 2 + 1; }
int rightt(int i) { return i * 2 + 2; }
int middle(int l, int r) { return (l + r) / 2; }
void recalculate(int i) { tree[i] = tree[leftt(i)] + tree[rightt(i)]; }

void build(int ss = 0, int se = n - 1, int si = 0)
{
    if (ss == se)
        tree[si] = arr[ss];
    else
    {
        int m = middle(ss, se);
        build(ss, m, leftt(si));
        build(m + 1, se, rightt(si));
        recalculate(si);
    }
}

int sumQuery(int l, int r, int ss = 0, int se = n - 1, int si = 0)
{
    if (ss >= l && se <= r)
        return tree[si];
    int ans = 0;
    int mid = middle(ss, se);
    if (l <= mid)
        ans += sumQuery(l, r, ss, mid, leftt(si));
    if (r > mid)
        ans += sumQuery(l, r, mid + 1, se, rightt(si));
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
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << sumQuery(l, r) << endl;
    }
    return 0;
}