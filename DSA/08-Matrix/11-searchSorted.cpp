//  Search in a Row-Wise and Column-Wise Sorted Matrix

#include <iostream>
using namespace std;

int R, C;
int arr[10][10];

// Searching start from Top-Right corner
pair<int, int> search(int val)
{
    int i = 0, j = C - 1;
    while (i < R && j >= 0)
    {
        if (arr[i][j] == val)
            return {i, j};
        if (arr[i][j] > val)
            j--;
        else
            i++;
    }
    return {-1, -1};
}

void create()
{
    int matrix[4][4] = {{10, 20, 30, 40},
                        {15, 25, 35, 45},
                        {27, 29, 37, 48},
                        {32, 33, 39, 50}};
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            arr[i][j] = matrix[i][j];
}

int main()
{
    // cin >> R >> C;
    R = 4, C = 4;
    create();
    int x;
    cin >> x;
    pair<int, int> p = search(x);
    cout << p.first << " " << p.second;
}