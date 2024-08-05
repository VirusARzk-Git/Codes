
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;
#define int long long
#define all(x) x.begin(), x.end()
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)
int answer()
{
    int n, c;
    cin >> n >> c;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int mn = arr[0] + 1, j = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] + i + 1 < mn)
            mn = arr[i] + i + 1, j = i;
    }
    c -= mn;
    if (c < 0)
        return 0;
    if (c == 0)
        return 1;
    arr[j] = 0;
    for (int i = 0; i < n; i++)
        if (arr[i])
            arr[i] += min(i + 1, n - i);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
    // for (int i = 2; i <= n; i++)
    //     if (arr[i])
    //         arr[i - 1] += min(i, n + 1 - i);

    sort(arr, arr + n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > c)
        {
            return i;
        }
    }
    return n;
}

signed main()
{
    noTLE;
    testcase_chalao_bhai cout << answer() << endl;
    return 0;
}