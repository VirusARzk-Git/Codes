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
void recalculate(int i) { tree[i] = min(tree[leftt(i)], tree[rightt(i)]); }

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

int minQuery(int l, int r, int ss = 0, int se = n - 1, int si = 0)
{
    if (ss >= l && se <= r)
        return tree[si];
    int ans = LLONG_MAX;
    int mid = middle(ss, se);
    if (l <= mid)
        ans = min(ans, minQuery(l, r, ss, mid, leftt(si)));
    if (r > mid)
        ans = min(ans, minQuery(l, r, mid + 1, se, rightt(si)));
    return ans;
}

void updateQuery(int k, int x, int ss = 0, int se = n - 1, int si = 0)
{
    if (ss == se)
        tree[si] = x;
    else
    {
        int mid = middle(ss, se);
        if (k <= mid)
            updateQuery(k, x, ss, mid, leftt(si));
        else
            updateQuery(k, x, mid + 1, se, rightt(si));
        recalculate(si);
    }
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
        int qtype;
        cin >> qtype;
        if (qtype == 1)
        {
            int i, x;
            cin >> i;
            cin >> x;
            // i--;
            updateQuery(i, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            // l--, r--;
            r--;
            cout << minQuery(l, r) << endl;
        }
    }
    // for (int i = 0; i < 4 * n; i++)
    //     cout << tree[i] << ' ';
    return 0;
}