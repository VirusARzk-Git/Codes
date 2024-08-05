#include <bits/stdc++.h>
using namespace std;
#define int long long

void code()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int brr[m];
    for (int i = 0; i < m; i++)
        cin >> brr[i];
    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < m)
    {
        if (arr[i] < brr[j])
            i++;
        else if (arr[i] > brr[j])
            j++;
        else
        {
            int c1 = 1, c2 = 1;
            while (i + 1 < n && arr[i] == arr[i + 1])
            {
                c1++;
                i++;
            }
            while (j + 1 < m && brr[j] == brr[j + 1])
            {
                c2++;
                j++;
            }
            ans += c1 * c2;
            i++,j++;
        }
    }
    cout << ans;
}

signed main()
{
    code();
    return 0;
}