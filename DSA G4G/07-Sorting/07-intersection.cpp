//  Intersection of two sorted arrays

#include <iostream>
using namespace std;

void intersectionOfTwoSortedArrays(int *a, int n, int *b, int m)
{
    int l = min(n, m);
    int ans[l];
    int i = 0, j = 0, k = 0;
    while (i < n and j < m)
    {
        if (i and a[i] == a[i - 1])
            i++;
        else if (a[i] < b[j])
            i++;
        else if (a[i] > b[j])
            j++;
        else
            ans[k++] = a[i++], j++;
    }
    for (int i = 0; i < k; i++)
        cout << ans[i] << ' ';
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    intersectionOfTwoSortedArrays(a, n, b, m);
}