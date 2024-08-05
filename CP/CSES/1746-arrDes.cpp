#include <bits/stdc++.h>
using namespace std;

#define int long long
using vi = vector<int>;
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int mod = 1e9 + 7;
int m, n;
vi arr;
vector<vi> dp;

int check(int i)
{

    if (i == n)
    {
        // for (int j : arr)
        //     cout << j << " ";
        // cout << endl;
        return 1;
    }

    if (i > 0 && arr[i] && abs(arr[i] - arr[i - 1]) > 1)
        return 0;

    if (arr[i] != 0)
        return check(i + 1);

    if (i == 0)
    {
        int sum = 0;
        for (int j = 1; j <= m; j++)
        {
            arr[i] = j;
            (sum += check(i + 1)) %= mod;
            arr[i] = 0;
        }
        return sum;
    }
    else
    {
        int sum = 0;

        arr[i] = arr[i - 1];
        sum += check(i + 1);

        if (arr[i - 1] > 1)
        {
            arr[i] = arr[i - 1] - 1;
            sum += check(i + 1);
        }
        if (arr[i - 1] < m)
        {
            arr[i] = arr[i - 1] + 1;
            sum += check(i + 1);
        }
        arr[i] = 0;
        return sum;
    }
}

void code()
{
    cin >> n;
    cin >> m;
    arr.resize(n);
    dp.resize(n + 1, vector<int>(1 + m, 0));
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << check(0);
}

signed main()
{
    noTLE;

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //  tCases
    code();
    return 0;
}