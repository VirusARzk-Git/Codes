#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int pre[1000];
int suf[1000];

void create(int *arr, int n)
{
    pre[1] = arr[1];
    for (int i = 2; i <= n; i++)
        pre[i] = gcd(pre[i - 1], arr[i]);

    suf[n] = arr[n];
    for (int i = n - 1; i > 0; i--)
        suf[i] = gcd(suf[i + 1], arr[i]);
}

signed main()
{
    int n, q;
    cin >> n >> q;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    create(arr, n);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << gcd(pre[l - 1], suf[r + 1]) << endl;
    }
}

//          GCDQ            CodeChef