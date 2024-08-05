#include <iostream>
using namespace std;
int R;
int arr[100][100];

// Rotate 90 degrees anti-clockwise

void transpose()
{
    for (int i = 0; i < R; i++)
        for (int j = i + 1; j < R; j++)
            swap(arr[i][j], arr[j][i]);
}

void reverseAboutX()
{
    int C = R;
    for (int j = 0; j < C; j++)
        for (int i = 0; i < R / 2; i++)
            swap(arr[i][j], arr[R - 1 - i][j]);
}

void reverseAboutY()
{
    int C = R;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C / 2; j++)
            swap(arr[i][j], arr[i][C - 1 - j]);
}

void print()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
            if (arr[i][j] <= 9)
                cout << arr[i][j] << "  ";
            else
                cout << arr[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

int main()
{
    cin >> R;
    int val = 1;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < R; j++)
            arr[i][j] = val++;
    print();
    transpose();
    reverseAboutX();
    print();
}