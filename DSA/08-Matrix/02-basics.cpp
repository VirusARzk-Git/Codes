#include <iostream>
using namespace std;

int main()
{
    int m = 3, n = 2;

    int *arr[m];

    // int **arr;
    // arr = new int *[m];

    for (int i = 0; i < m; i++)
        arr[i] = new int[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = i + j;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << ' ';
    return 0;
}