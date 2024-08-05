#include <iostream>
#include <vector>
using namespace std;

#define int long long
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)
#define array_input_lelo_bhai   \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define array_print_kardo_bhai  \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '

int n, m;
int arr[1001][1001];

int add(int i, int j)
{
    if (i < 0 or i >= n)
        return 0;
    if (j < 0 or j >= m)
        return 0;
    if (arr[i][j] == 0)
        return 0;
    else
    {
        int x = arr[i][j];
        arr[i][j] = 0;
        return x;
    }
}

int func(int i, int j, int sum = 0)
{
    int a = add(i, j);
    int b = add(i, j + 1);
    int c = add(i + 1, j);
    int d = add(i, j - 1);
    int e = add(i - 1, j);
    int ans = sum + a + b + c + d + e;
    if (b)
        ans += func(i, j + 1);
    if (c)
        ans += func(i + 1, j);
    if (d)
        ans += func(i, j - 1);
    if (e)
        ans += func(i - 1, j);
    return ans;
}

void code_iske_andar_hai()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    int ans = 0;
    // bool h[n][m] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] != 0)
                ans = max(ans, func(i, j));
    cout << ans << endl;
}

signed main()
{
    noTLE;
    testcase_chalao_bhai
    code_iske_andar_hai();
    return 0;
}