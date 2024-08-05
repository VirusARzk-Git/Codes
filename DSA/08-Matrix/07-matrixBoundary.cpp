#include <iostream>
using namespace std;
int R, C;
int arr[100][100];

void MatrixBoundary()
{
    if (C == 1)
        for (int i = 0; i < R; i++)
            cout << arr[i][0] << " ";
    else if (R == 1)
        for (int i = 0; i < C; i++)
            cout << arr[0][i] << ' ';
    else
    {
        for (int i = 0; i < C; i++)
            cout << arr[0][i] << ' ';
        for (int i = 1; i < R; i++)
            cout << arr[i][C - 1] << ' ';
        for (int i = C - 2; i >= 0; i--)
            cout << arr[R - 1][i] << ' ';
        for (int i = R - 2; i > 0; i--)
            cout << arr[i][0] << ' ';
    }
}

int main()
{
    cin >> R >> C;
    int val = 1;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            arr[i][j] = val++;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            if (arr[i][j] <= 9)
                cout << arr[i][j] << "  ";
            else
                cout << arr[i][j] << ' ';
        cout << endl;
    }
    MatrixBoundary();
}