#include <iostream>
#include <cmath>
using namespace std;

int N;
int sudoku[9][9];

bool isSafe(int i, int j, int n)
{
    for (int k = 0; k < N; k++)
        if (sudoku[k][j] == n || sudoku[i][k] == n)
            return false;
    int s = sqrt(N);
    int rs = i - i % s;
    int cs = j - j % s;
    for (int idx1 = 0; idx1 < s; idx1++)
        for (int idx2 = 0; idx2 < s; idx2++)
            if (sudoku[idx1 + rs][idx2 + cs] == n)
                return false;
    return true;
}

bool solveSudoku(int i = 0, int j = 0)
{
    if (i == N - 1 && j == N)
        return true;

    if (j == N)
        i++, j = 0;

    if (sudoku[i][j])
        return solveSudoku(i, j + 1);

    for (int n = 1; n <= N; n++)
    {
        if (isSafe(i, j, n))
        {
            sudoku[i][j] = n;
            if (solveSudoku(i, j + 1))
                return true;
        }
        sudoku[i][j] = 0;
    }
    return false;
}

void printSudoku()
{
    for (int i = 0; i < N; i++)
    {
        cout << endl;
        for (int j = 0; j < N; j++)
            cout << sudoku[i][j] << ' ';
    }
}

void solve()
{
    if (solveSudoku())
        printSudoku();
    else
        cout << "Invalid Sudoku!" << endl;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> sudoku[i][j];
    solve();
}