#include <bits/stdc++.h>
using namespace std;
/// @brief
void code_iske_andar_hai()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = res ^ arr[i], res = res ^ i;
    int setBit = res & ~(res - 1);
    int L = 0, R = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] & setBit)
            L = L ^ arr[i];
        else
            R = R ^ arr[i];
        if (i & setBit)
            L = L ^ i;
        else
            R = R ^ i;
    }
    bool isLMissing = true;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == L)
        {
            isLMissing = false;
            break;
        }
    }
    if (isLMissing == true)
        cout << "Missing Number: " << L << " ,Repeating Number: " << R << endl;
    else
        cout << "Missing Number: " << R << " ,Repeating Number: " << L << endl;
}

signed main()
{
    int virus_arzk;
    cin >> virus_arzk;
    while (virus_arzk--)
        code_iske_andar_hai();
    return 0;
}