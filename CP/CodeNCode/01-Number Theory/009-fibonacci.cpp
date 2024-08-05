#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 1; i <= n; i++)
#define int long long int
int arr[3];
int I[3][3], T[3][3];
#define mod 1000000007

void mul(int A[3][3], int B[3][3], int dim = 2)
{
    int res[dim + 1][dim + 1];
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            res[i][j] = 0;
            for (int k = 1; k <= dim; k++)
            {
                int x = (A[i][k] * B[k][j]) % mod;
                res[i][j] = (res[i][j] + x) % mod;
            }
        }
    }
    for (int j = 1; j <= dim; j++)
    {
        for (int k = 1; k <= dim; k++)
        {
            A[j][k] = res[j][k];
        }
    }
}

int getFib(int n)
{
    if (n <= 2)
        return arr[n];

    I[2][2] = I[1][1] = 1;
    I[1][2] = I[2][1] = 0;
    T[1][1] = 0;
    T[1][2] = T[2][1] = T[2][2] = 1;
    n--;

    while (n)
    {
        if (n % 2)
            mul(I, T, 2), n--;
        else
            mul(T, T, 2), n /= 2;
    }
    int Fn = (arr[1] * I[1][1] + arr[2] * I[2][1]) % mod;
    return Fn;
}

signed main()
{
    int t, m;
    cin >> t;
    while (t--)
    {
        cin >> arr[1] >> arr[2] >> m, m++;
        cout << getFib(m) << endl;
    }
}