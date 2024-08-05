#include <bits/stdc++.h>
using namespace std;

// Function to print Tic-Tac-Toe board
void printBoard(char board[3][3])
{
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

// Function to check if the game has ended or not
bool isGameOver(char board[3][3])
{
    // Check if any player has won
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return true;

    // Check if the game is in progress
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // If there is an empty cell then the game is still in progress
            if (board[i][j] == ' ')
                return false;
        }
    }

    // If all the cells are filled and no player has won then the game has ended
    return true;
}

// Function to check if the move is valid or not
bool isValidMove(int x, int y, char board[3][3])
{
    // Check if the move is within the board
    if (x < 0 || x > 2 || y < 0 || y > 2)
        return false;

    // Check if the cell is empty
    if (board[x][y] != ' ')
        return false;

    return true;
}

// Function to play the game
void playGame()
{
    char board[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }

    // Player 1 is 'X' and Player 2 is 'O'
    char currentPlayer = 'X';
    bool gameOver = false;
    int moves = 0;

    while (!gameOver)
    {
        printBoard(board);
        int x, y;
        cout << "Enter the row and column to make a move: ";
        cin >> x >> y;

        if (isValidMove(x, y, board))
        {
            board[x][y] = currentPlayer;
            moves++;
        }
        else
        {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        if (isGameOver(board))
        {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        }
        else if (moves == 9)
        {
            printBoard(board);
            cout << "It's a draw!" << endl;
            gameOver = true;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main()
{
    playGame();
    return 0;
}
