#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int L[n], R[n];
    for (int i = 0; i < n; i++)
        cin >> L[i];
    for (int i = 0; i < n; i++)
        cin >> R[i];
    int hashh[1001] = {0};
    for (int i = 0; i < n; i++)
        hashh[L[i]]++, hashh[R[i] + 1]--;
    int maxM = 0, res = 0;
    for (int i = 1; i < 1001; i++)
    {
        hashh[i] += hashh[i - 1];
        if (maxM < hashh[i])
            maxM = hashh[i], res = i;
    }
    cout << res << endl;
}