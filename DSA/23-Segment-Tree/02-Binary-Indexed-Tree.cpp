#include <iostream>
using namespace std;

int n, *arr, *bITree;

int getSum(int i)
{
    i += 1;
    int sum = 0;
    while (i > 0)
    {
        sum += bITree[i];
        i -= i & (-i);
    }
    return sum;
}

void update(int i, int diff)
{
    i += 1;
    while (i <= n)
    {
        bITree[i] += diff;
        i += i & (-i);
    }
}

void constructBITree()
{
    for (int i = 1; i <= n; i++)
        bITree[i] = 0;

    for (int i = 0; i < n; i++)
        update(i + 1, arr[i]);
}

void printBITree()
{
    for (int i = 1; i <= n; i++)
        cout << bITree[i] << ' ';
}

int main()
{
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bITree = new int[n + 1];
    constructBITree();

    int query;
    cin >> query;
    while (query--)
    {
        int queryType;
        cin >> queryType;
        if (queryType == 1)
        {
            int i, diff;
            cin >> i >> diff;
            update(i, diff - arr[i]);
            arr[i] = diff;
        }
        else if (queryType == 2)
        {
            int idx;
            cin >> idx;
            cout << getSum(idx) << '\n';
        }
        else
            printBITree();
    }
}