#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char currentPlayer = 'X';

// Function to display the Tic-Tac-Toe board
void displayBoard() {
    cout << "Tic-Tac-Toe" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}

// Function to check if the game is over
bool isGameOver() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    
    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    cout << "It's a draw!" << endl;
    return true;
}

// Function to switch players
void switchPlayer() {
    if (currentPlayer == 'X') currentPlayer = 'O';
    else currentPlayer = 'X';
}

int main() {
    bool gameover = false;
    int row, col;
    
    while (!gameover) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
        } else {
            board[row][col] = currentPlayer;
            gameover = isGameOver();
            switchPlayer();
        }
    }
    
    displayBoard();
    cout << "Player " << currentPlayer << " wins!" << endl;
    
    return 0;
}
