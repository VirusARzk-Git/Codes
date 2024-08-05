#include <bits/stdc++.h>
using namespace std;
#define int long long int
int arr[1000001];
int ppp[1000001]={1};
void sieve()
{
    int n = 1000001;
    for (int i = 0; i < n; i++)
    {
        arr[i] = 1;
    }
    arr[0] = arr[1] = 0;
    for (int i = 2; i * i < n; i++)
    {
        if (arr[i] == 1)
        {
            for (int j = i * i; j < n; j += i)
                arr[j] = 0;
        }
    }
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 1)
            cnt++;
        if (arr[cnt] == 1)
            ppp[i] = 1;
        else
            ppp[i] = 0;
        ppp[i] += ppp[i - 1];
    }
}

signed main()
{
    sieve();
    int q;
    cin >> q;
    while (q--)
    {
        int c = 0;
        int l, r;
        cin >> l >> r;
        // for (; l <= r; l++)
        //     c += ppp[l];
        cout << ppp[r] - ppp[l-1] << endl;
    }
}