#include <iostream>
using namespace std;

int *tree, *arr;
int constructST(int ss, int se, int si)
{
    if (ss == se)
        return tree[si] = arr[ss];
    int mid = (ss + se) / 2;
    return tree[si] = constructST(ss, mid, 2 * si + 1) + constructST(mid + 1, se, 2 * si + 2);
}

int getSum(int qs, int qe, int ss, int se, int si)
{
    if (se < qs || ss > qe)
        return 0;
    if (ss >= qs && se <= qe)
        return tree[si];
    int mid = (ss + se) / 2;
    return getSum(qs, qe, ss, mid, 2 * si + 1) + getSum(qs, qe, mid + 1, se, 2 * si + 2);
}

void update(int ss, int se, int i, int si, int diff)
{
    if (i < ss || i > se)
        return;
    tree[si] += diff;
    if (se > ss)
    {
        int mid = (ss + se) / 2;
        update(ss, mid, i, 2 * si + 1, diff);
        update(mid + 1, se, i, 2 * si + 2, diff);
    }
}

int main()
{
    int n;
    cin >> n;
    arr = new int[n];
    tree = new int[4 * n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    constructST(0, n - 1, 0);
    for (int i = 0; i < 4 * n; i++)
        cout << tree[i] << ' ';

    int q;
    cin >> q;
    while (q--)
    {
        int queryType;
        cin >> queryType;
        if (queryType == 1)
        {
            int i, val;
            cin >> i >> val;
            update(0, n - 1, i, 0, val - arr[i]);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << getSum(l, r, 0, n - 1, 0) << endl;
        }
    }
    return 0;
}