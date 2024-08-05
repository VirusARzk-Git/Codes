#include <iostream>
using namespace std;

int n;
bool chessBoard[27][27];

void printBoard()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << chessBoard[i][j] << ' ';
        cout << endl;
    }
}

bool isSafe(int row, int col)
{
    for (int i = 0; i < col; i++)
        if (chessBoard[row][i])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (chessBoard[i][j])
            return false;
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (chessBoard[i][j])
            return false;
    return true;
}

bool solveRec(int col)
{
    if (col == n)
        return true;
    for (int i = 0; i < n; i++)
        if (isSafe(i, col))
        {
            chessBoard[i][col] = 1;
            if (solveRec(col + 1))
                return true;
            chessBoard[i][col] = 0;
        }
    return false;
}

void solve()
{
    if (solveRec(0))
        printBoard();
    else
        cout << "No such chessBoard orientation exists!" << endl;
}

int main()
{
    cin >> n;
    solve();
}