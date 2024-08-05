#include <iostream>
#include <algorithm>

using namespace std;

//  Median Of A Row-Wise Sorted Matrix

// Odd-Sized Matrix
// All Distict Elements
int R, C;
int mat[10][10];

int matMed()
{
    int min = mat[0][0], max = mat[0][C - 1];
    for (int i = 1; i < R; i++)
    {
        if (mat[i][0] < min)
            min = mat[i][0];
        if (mat[i][C - 1] > max)
            max = mat[i][C - 1];
    }
    int medPos = (R * C + 1) / 2;
    while (min < max)
    {
        int mid = (min + max) / 2;
        int midPos = 0;
        for (int i = 0; i < R; i++)
            midPos += upper_bound(mat[i], mat[i] + C, mid) - mat[i];
        if (midPos < medPos)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

void create()
{
    int matrix[3][5] = {{5, 11, 10, 301, 400},
                        {1, 2, 30, 142, 326},
                        {12, 13, 115, 117, 219}};
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            mat[i][j] = matrix[i][j];
}

int main()
{
    // cin >> R >> C;
    R = 3, C = 5;
    create();
    cout << matMed();
}