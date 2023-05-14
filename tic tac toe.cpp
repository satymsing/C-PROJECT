#include <iostream>
#include <iomanip>
using namespace std;

// Function to print the game board
void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(2) << board[i][j];
            if (j != 2) {
                cout << " |";
            }
        }
        if (i != 2) {
            cout << endl << "---------" << endl;
        }
    }
    cout << endl;
}

// Function to check if the game is over
bool gameOver(char board[3][3], char symbol) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return true;
    }
    return false;
}

// Function to play the game
void playGame() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char player = 'X';
    int row, col;
    int moves = 0;
    while (moves < 9) {
        printBoard(board);
        cout << "Player " << player << "'s turn. Enter row (1-3) and column (1-3): ";
        cin >> row >> col;
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Invalid input. Try again." << endl;
            continue;
        }
        if (board[row-1][col-1] == 'X' || board[row-1][col-1] == 'O') {
            cout << "That spot is already taken. Try again." << endl;
            continue;
        }
        board[row-1][col-1] = player;
        if (gameOver(board, player)) {
            printBoard(board);
            cout << "Player " << player << " wins!" << endl;
            return;
        }
        player = (player == 'X') ? 'O' : 'X';
        moves++;
    }
    printBoard(board);
    cout << "Game over. It's a tie!" << endl;
}

int main() {
    playGame();
    return 0;
}