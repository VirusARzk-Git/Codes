#include <iostream>
using namespace std;

int KnapSack(int *val, int *wt, int n, int w)
{
    if (n == 0 || w == 0)
        return 0;
    if (wt[n - 1] > w)
        return KnapSack(val, wt, n - 1, w);
    else
        return max(val[n - 1] + KnapSack(val, wt, n - 1, w - wt[n - 1]), KnapSack(val, wt, n - 1, w));
}

int main()
{
    int n;
    cin >> n;
    int *val = new int[n];
    int *wt = new int[n];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    int w;
    cin >> w;
    cout << KnapSack(val, wt, n, w);
}