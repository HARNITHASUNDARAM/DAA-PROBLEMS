#include <stdio.h>
#include <stdbool.h>

#define N 8 // Size of the chessboard (N x N)

// Function to print the solution (the chessboard with queens placed)
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
// This check is done for all previous rows and columns
bool isSafe(int board[N][N], int row, int col) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Recursive function to solve the N Queen problem
bool solveNQueens(int board[N][N], int row) {
    // If all queens are placed, return true
    if (row >= N) {
        return true;
    }

    // Try placing the queen in all columns of the current row
    for (int col = 0; col < N; col++) {
        // Check if the queen can be placed
        if (isSafe(board, row, col)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the next queen
            if (solveNQueens(board, row + 1)) {
                return true;
            }

            // If placing queen in board[row][col] doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    // If the queen cannot be placed in any column of this row, return false
    return false;
}

int main() {
    int board[N][N] = {0}; // Initialize the chessboard with 0s (empty spaces)

    if (solveNQueens(board, 0)) {
        printSolution(board);
    } else {
        printf("Solution does not exist\n");
    }

    return 0;
}
