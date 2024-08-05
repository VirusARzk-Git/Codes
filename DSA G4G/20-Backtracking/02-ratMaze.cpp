#include <iostream>
#include <vector>
using namespace std;

int n;
bool maze[100][100];
bool sol[100][100];

bool isSafe(int i, int j)
{
    return (i < n && j < n && maze[i][j]);
}

bool solveMaze(int i, int j)
{
    if (i == n - 1 && j == n - 1)
        return true;
    if (isSafe(i, j))
    {
        sol[i][j] = 1;
        if (solveMaze(i + 1, j) || solveMaze(i, j + 1))
            return true;
        sol[i][j] = 0;
    }
    return false;
}

void printMaze()
{
    sol[n - 1][n - 1] = 1;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << sol[i][j] << ' ';
        cout << endl;
    }
}

void ratInMaze(int n)
{
    if (solveMaze(0, 0))
        printMaze();
    else
        cout << "No Valid Path exists!" << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];
    ratInMaze(n);
}