#include <iostream>
using namespace std;

int getMin(int *coins, int n, int amt)
{
    if (amt == 0)
        return 0;
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
        if (coins[i] <= amt)
        {
            int subRes = getMin(coins, n, amt - coins[i]);
            if (subRes != INT_MAX)
                res = min(res, subRes + 1);
        }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int *coins = new int[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int amt;
    cin >> amt;
    cout << getMin(coins, n, amt);
}