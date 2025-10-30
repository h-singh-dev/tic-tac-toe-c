#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

// Function prototypes
void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]);
int checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player);
int checkDraw(char board[BOARD_SIZE][BOARD_SIZE]);
int makeMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char player);
int isValidMove(int row, int col);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int row, col;
    char currentPlayer = 'X';
    int gameOver = 0;

    // Initialize the board with empty spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X\nPlayer 2: O\n");
    printf("\n=== How to Play ===\n");
    printf("Enter row and column numbers (0-2) when prompted.\n");
    printf("Example: Row 0, Column 0 = Top-left corner\n\n");

    // Game loop
    while (!gameOver) {
        // Display the current board
        displayBoard(board);

        // Get player move
        printf("Player %c's turn.\n", currentPlayer);
        printf("Enter row (0-2): ");
        
        // Clear input buffer and validate scanf return value
        if (scanf("%d", &row) != 1) {
            // Clear invalid input from buffer
            while (getchar() != '\n');
            printf("Invalid input! Please enter a number.\n");
            continue;
        }
        
        printf("Enter column (0-2): ");
        if (scanf("%d", &col) != 1) {
            // Clear invalid input from buffer
            while (getchar() != '\n');
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        // Validate and make move
        if (isValidMove(row, col)) {
            if (makeMove(board, row, col, currentPlayer)) {
                // Check for win
                if (checkWin(board, currentPlayer)) {
                    displayBoard(board);
                    printf("Player %c wins!\n", currentPlayer);
                    gameOver = 1;
                } 
                // Check for draw
                else if (checkDraw(board)) {
                    displayBoard(board);
                    printf("It's a draw!\n");
                    gameOver = 1;
                } 
                // Switch players
                else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            } else {
                printf("Invalid move! Cell already occupied.\n");
            }
        } else {
            printf("Invalid move! Row and column must be between 0-2.\n");
        }
    }

    printf("Thanks for playing!\n");
    return 0;
}

// Function to display the game board
void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < BOARD_SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1; // Win found
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1; // Win found
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1; // Win found
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1; // Win found
    }

    return 0; // No win
}

// Function to check if the game is a draw
int checkDraw(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Not a draw, empty cell found
            }
        }
    }
    return 1; // Draw, no empty cells
}

// Function to make a move on the board
int makeMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return 1; // Move successful
    }
    return 0; // Move failed, cell occupied
}

// Function to validate if a move is within board boundaries
int isValidMove(int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE);
}

