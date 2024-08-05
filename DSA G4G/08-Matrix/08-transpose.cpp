#include <iostream>
using namespace std;
int n;
int arr[100][100];

void transpose()
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(arr[i][j], arr[j][i]);
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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
    cin >> n;
    int val = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = val++;
    print();
    transpose();
    print();
}