#include <iostream>
#include <algorithm>
using namespace std;

int Guests(int *L, int *R, int n)
{
    int hashh[2360] = {0};
    for (int i = 0; i < n; i++)
        hashh[L[i]]++, hashh[R[i] + 1]--;
    int maxM = 0;
    for (int i = 1; i < 2360; i++)
    {
        hashh[i] += hashh[i - 1];
        if (maxM < hashh[i])
            maxM = hashh[i];
    }
    return maxM;
}

int maxGuest(int *arr, int *dep, int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i = 1, j = 0, res = 1, curr = 1;
    while (i < n and j < n)
    {
        if (arr[i] <= dep[j])
            curr++, i++;
        else
            curr--, j++;
        res = max(res, curr);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arrival[n], departure[n];
    for (int i = 0; i < n; i++)
        cin >> arrival[i];
    for (int i = 0; i < n; i++)
        cin >> departure[i];
    cout << maxGuest(arrival, departure, n);
}