#include <iostream>
#include <algorithm>
using namespace std;

struct Interval
{
    int start;
    int end;
};

bool myComp(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

int zMergeIntervals(Interval *arr, int n) // By VirusARzk
{
    sort(arr, arr + n, myComp);
    int k = 0;
    Interval d[n];
    d[0].start = arr[0].start, d[0].end = arr[0].end;
    for (int i = 1; i < n; i++)
        if (arr[i - 1].end >= arr[i].start)
            d[k].end = max(d[k].end, arr[i].end);
        else
            d[++k].start = arr[i].start, d[k].end = arr[i].end;
    for (int i = 0; i <= k; i++)
        arr[i].start = d[i].start, arr[i].end = d[i].end;
    return k;
}

int mergeIntervals(Interval *arr, int n) // GFG
{
    sort(arr, arr + n, myComp);
    int res = 0;
    for (int i = 1; i < n; i++)
        if (arr[res].end >= arr[i].start)
        {
            arr[res].end = max(arr[res].end, arr[i].end);
            // arr[res].start = min(arr[res].start, arr[i].start);
        }
        else
            res++, arr[res] = arr[i];
    return res;
}

int main()
{
    int n;
    cin >> n;
    Interval arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i].start >> arr[i].end;
    int k = mergeIntervals(arr, n);
    for (int i = 0; i <= k; i++)
        cout << arr[i].start << ',' << arr[i].end << endl;
}