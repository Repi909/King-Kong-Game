#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

// Define the game constants
const int BOARD_WIDTH = 20;
const int BOARD_HEIGHT = 20;
const int SNAKE_INITIAL_LENGTH = 3;
const char SNAKE_HEAD = '@';
const char SNAKE_BODY = 'o';
const char FOOD = '*';

// Define the game variables
char board[BOARD_HEIGHT][BOARD_WIDTH];
int snakeX[SNAKE_INITIAL_LENGTH];
int snakeY[SNAKE_INITIAL_LENGTH];
int foodX, foodY;
int snakeLength;
int score;

// Initialize the game board
void initBoard() {
    // Set all board elements to empty
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = ' ';
        }
    }

    // Place the snake at the center of the board
    int x = BOARD_WIDTH / 2;
    int y = BOARD_HEIGHT / 2;
    for (int i = 0; i < SNAKE_INITIAL_LENGTH; i++) {
        snakeX[i] = x - i;
        snakeY[i] = y;
        board[y][x-i] = SNAKE_BODY;
    }

    // Place the food randomly on the board
    srand(time(NULL));
    foodX = rand() % BOARD_WIDTH;
    foodY = rand() % BOARD_HEIGHT;
    board[foodY][foodX] = FOOD;

    // Set the initial snake length and score
    snakeLength = SNAKE_INITIAL_LENGTH;
    score = 0;
}

// Print the game board
void printBoard() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

// Move the snake
void moveSnake(int dx, int dy) {
    // Move the head of the snake
    int x = snakeX[0] + dx;
    int y = snakeY[0] + dy;

    // Check if the snake has collided with the walls or itself
    if (x < 0 || x >= BOARD_WIDTH || y < 0 || y >= BOARD_HEIGHT || board[y][x] == SNAKE_BODY) {
        cout << "Game over!" << endl;
        exit(0);
    }

    // Check if the snake has eaten the food
    if (x == foodX && y == foodY) {
        // Increase the score and snake length
        score += 10;
        snakeLength++;

        // Place the new food randomly on the board
        foodX = rand() % BOARD_WIDTH;
        foodY = rand() % BOARD_HEIGHT;
        board[foodY][foodX] = FOOD;
    }
    else {
        // Move the tail of the snake
        board[snakeY[snakeLength-1]][snakeX[snakeLength-1]] = ' ';
        for (int i = snakeLength-1; i > 0; i--) {
            snakeX[i] = snakeX[i-1];
            snakeY[i] = snakeY[i-1];
            board[snakeY[i]][snakeX[i]] = SNAKE_BODY;
        }
    }

    // Move the head of the snake
    snakeX[0] = x;
    snakeY[0] = y;
    board[y][x] = SNAKE_HEAD;

    }

// Handle keyboard input
void handleInput() {
// Get the keyboard input
char key = getch();
// Move the snake based on the key pressed
switch(key) {
    case 'w': moveSnake(0, -1); break;
    case 's': moveSnake(0, 1); break;
    case 'a': moveSnake(-1, 0); break;
    case 'd': moveSnake(1, 0); break;
    case 'q': exit(0); break;
}
}

// Main game loop
int main() {
// Initialize the game board
initBoard();
// Main game loop
while (true) {
    // Clear the console
    system("cls");

    // Handle keyboard input
    handleInput();

    // Print the game board
    printBoard();
    cout << "Score: " << score << endl;

}

return 0;
}