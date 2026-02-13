package TicTacToe;

import TicTacToe.Model.Board;
import TicTacToe.Model.GameStatus;
import TicTacToe.Model.PieceType;
import TicTacToe.Model.Player;
import TicTacToe.Model.PlayingPieceO;
import TicTacToe.Model.PlayingPieceX;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class TicTacToeGame {

  Deque<Player> players;
  Board gameBoard;
  Player winner;

  public void initializeGame() {
    gameBoard = new Board(3);

    players = new LinkedList<>();

    PlayingPieceX p1 = new PlayingPieceX();
    Player player1 = new Player("Player 1", p1);
    PlayingPieceO p2 = new PlayingPieceO();
    Player player2 = new Player("Player 2", p2);

    players.add(player1);
    players.add(player2);
  }

  public GameStatus startGame() {
    boolean noWinner = true;
    while (noWinner) {
      Player currentPlayer = players.peek();

      gameBoard.displayBoard();

      if (gameBoard.isBoardFull()) {
        return GameStatus.DRAW;
      }

      // Read the user input
      System.out.print(
        "Player: " + currentPlayer.name + " - Please enter [row, column]: "
      );
      Scanner inputScanner = new Scanner(System.in);
      String s = inputScanner.nextLine();
      String[] values = s.split(",");
      int inputRow = Integer.valueOf(values[0]);
      int inputColumn = Integer.valueOf(values[1]);

      boolean validMove = gameBoard.placePiece(
        inputRow,
        inputColumn,
        currentPlayer.piece
      );
      if (!validMove) {
        System.out.println("Invalid move. Try again.");
        continue;
      }

      if (checkWinner(inputRow, inputColumn, currentPlayer.piece.pieceType)) {
        winner = currentPlayer;
        return GameStatus.WIN;
      }

      if (gameBoard.isBoardFull()) {
        return GameStatus.DRAW;
      }
      players.add(players.poll());
    }
    return GameStatus.DRAW;
  }

  public boolean checkWinner(int row, int col, PieceType pieceType) {
    boolean isWinner = true;
    // Check row
    for (int i = 0; i < gameBoard.size; i++) {
      if (
        gameBoard.board[row][i] == null ||
        gameBoard.board[row][i].pieceType != pieceType
      ) {
        isWinner = false;
        break;
      }
    }
    if (isWinner) {
      return true;
    }

    // Check column
    isWinner = true;
    for (int i = 0; i < gameBoard.size; i++) {
      if (
        gameBoard.board[i][col] == null ||
        gameBoard.board[i][col].pieceType != pieceType
      ) {
        isWinner = false;
        break;
      }
    }
    if (isWinner) {
      return true;
    }

    // Check diagonal
    isWinner = true;
    for (int i = 0; i < gameBoard.size; i++) {
      if (
        gameBoard.board[i][i] == null ||
        gameBoard.board[i][i].pieceType != pieceType
      ) {
        isWinner = false;
        break;
      }
    }
    if (isWinner) {
      return true;
    }

    // Check anti-diagonal
    isWinner = true;
    for (int i = 0; i < gameBoard.size; i++) {
      if (
        gameBoard.board[i][gameBoard.size - 1 - i] == null ||
        gameBoard.board[i][gameBoard.size - 1 - i].pieceType != pieceType
      ) {
        isWinner = false;
        break;
      }
    }
    return isWinner;
  }
}
