#include <iostream>
using namespace std;

int getWays(int *coins, int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    int res = getWays(coins, n - 1, sum);
    if (coins[n - 1] <= sum)
        res = res + getWays(coins, n, sum - coins[n - 1]);
    return res;
}

signed main()
{
    int n;
    cin >> n;
    int *coins = new int[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int amt;
    cin >> amt;
    cout << getWays(coins, n, amt);
}