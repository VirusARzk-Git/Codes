#include <iostream>
using namespace std;
int R, C;
int arr[100][100];

void printSnake()
{
    for (int i = 0; i < R; i++)
        if (i % 2)
            for (int j = C - 1; j >= 0; j--)
                cout << arr[i][j] << ' ';
        else
            for (int j = 0; j < C; j++)
                cout << arr[i][j] << ' ';
}

void printSnakeModified()
{
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            // for (int j = C - 1; j >= 0; j--)
            if (i % 2)
                cout << arr[i][C - 1 - j] << ' ';
            else
                cout << arr[i][j] << ' ';
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
    printSnake();
}