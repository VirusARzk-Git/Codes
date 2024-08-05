#include <iostream>
using namespace std;

void unionOfTwoSortedArrays(int *a, int n, int *b, int m)
{
    int ans[n + m];
    int i = 0, j = 0, k = 0;
    while (i < n and j < m)
    {
        if (i > 0 and a[i] == a[i - 1])
            i++;
        else if (j > 0 and b[j] == b[j - 1])
            j++;
        else if (a[i] < b[j])
            ans[k++] = a[i++];
        else if (a[i] > b[j])
            ans[k++] = b[j++];
        else
            ans[k++] = a[i++], j++;
    }
    // i--;
    // j--;
    while (i < n)
        if (i == 0 or a[i] != a[i - 1])
            ans[k++] = a[i++];
        else
            i++;

    while (j < m)
        if (j == 0 or b[j] != b[j - 1])
            ans[k++] = b[j++];
        else
            j++;

    for (int i = 0; i < k; i++)
        cout << ans[i] << ' ';
}

int main(int argc, char **c)
{
    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    unionOfTwoSortedArrays(a, n, b, m);
}
