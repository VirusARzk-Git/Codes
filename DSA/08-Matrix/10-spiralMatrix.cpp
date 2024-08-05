#include <iostream>
using namespace std;
int R, C;
int arr[100][100];

void spiralMatrix()
{
    int top = 0, left = 0, bottom = R - 1, right = C - 1;
    while (top <= bottom and left <= right)
    {
        for (int i = left; i <= right; i++)
            cout << arr[top][i] << " ";
        top++;
        for (int i = top; i <= bottom; i++)
            cout << arr[i][right] << " ";
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                cout << arr[bottom][i] << ' ';
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                cout << arr[i][left] << ' ';
            left++;
        }
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
    spiralMatrix();
}