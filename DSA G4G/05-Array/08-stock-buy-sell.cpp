#include <bits/stdc++.h>
using namespace std;

#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)
#define array_input_lelo_bhai   \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]

int maxProfit(int *prices, int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
        if (prices[i] > prices[i - 1])
            profit += (prices[i] - prices[i - 1]);
    return profit;
}

void code_iske_andar_hai()
{
    int n;
    cin >> n;
    array_input_lelo_bhai;
    cout << maxProfit(arr, n) << endl;
}

signed main()
{
    testcase_chalao_bhai
    code_iske_andar_hai();
    return 0;
}