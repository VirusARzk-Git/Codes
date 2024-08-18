int n;
vector<int> a;
vector<int> seg;

void build(int ind, int low, int high)
{
    if (low == high)
    {
        seg[ind] = a[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

void update(int ind, int low, int high, int index, int delta)
{
    if (low == high)
    {
        seg[ind] += delta;
        return;
    }
    int mid = low + (high - low) / 2;
    if (index <= mid)
        update(2 * ind + 1, low, mid, index, delta);
    else
        update(2 * ind + 2, mid + 1, high, index, delta);
    seg[ind] += delta;
}

int query(int ind, int low, int high, int l, int r)
{
    if (low >= l && high <= r)
        return seg[ind];
    if (high < l || low > r)
        return 0;
    int mid = low + (high - low) / 2;
    return query(2 * ind + 1, low, mid, l, r) +
           query(2 * ind + 2, mid + 1, high, l, r);
}