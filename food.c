
#include <stdlib.h> // Standard library, used for the rand() function

#include "food.h"   // Header file for food-related functions
#include "board.h"  // Header file for the game board
#include "snake.h"  // Header file for snake variables and functions

int foodX; // Stores the X-coordinate of the food
int foodY; // Stores the Y-coordinate of the food

int score = 0; // Keeps track of the player's score

// This function generates food at a random valid position on the board
void initializeFood(void)
{
    int i;
    int validPosition;

    do
    {
        validPosition = 1; // Assume the position is valid at first

        // Generate random coordinates within the board size
        foodX = rand() % BOARD_WIDTH;
        foodY = rand() % BOARD_HEIGHT;

        // Check if the generated position is on the snake's body
        for (i = 0; i < snakeLength; i++)
        {
            if (snakeX[i] == foodX && snakeY[i] == foodY)
            {
                validPosition = 0; // Invalid position, food overlaps with snake
                break;
            }
        }

    } while (!validPosition); // Keep generating until a valid position is found
}

// This function places the food symbol on the game board
void drawFood(void)
{
    board[foodY][foodX] = '*'; // '*' represents the food
}

// This function checks if the snake has eaten the food
void checkFoodCollision(void)
{
    // Compare the snake's head position with the food position
    if (snakeX[0] == foodX && snakeY[0] == foodY)
    {
        growSnake(); // Increase the snake's length

        score++; // Increase the player's score

        initializeFood(); // Generate new food after eating
    }
}