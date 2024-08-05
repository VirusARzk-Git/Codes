
#include <bits/stdc++.h>
using namespace std;
#define N 101
int arr[N][N], I[N][N];

void printMat(int arr[N][N], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cout << I[i][j] << ' ';
        }
        cout << endl;
    }
}

void mul(int A[][N], int B[][N], int dim)
{
    int res[dim + 1][dim + 1];
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < dim; k++)
                res[i][j] += B[i][k] * A[k][j];
        }
    for (int j = 0; j < dim; j++)
        for (int k = 0; k < dim; k++)
            A[j][k] = res[j][k];
}

void power(int arr[][N], int dim, int n)
{
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
    // for (int k = 0; k < n; k++)
    while (n)
    {
        if (n % 2)
            mul(I, arr, dim), n--;
        else
            mul(arr, arr, dim), n /= 2;
    }
}

signed main()
{
    int t, dim, n;
    cin >> t;
    while (t--)
    {
        cin >> dim >> n;
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++)
                cin >> arr[i][j];

        power(arr, dim, n);
        printMat(arr, dim);
    }
    return 0;
}

// SPOJ MPOW