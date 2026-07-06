#include <stdlib.h>

#include "food.h"
#include "board.h"
#include "snake.h"

int foodX;
int foodY;

int score = 0;

void initializeFood (void)
{
    int i;
    int validPosition;

    do 
    {
        validPosition = 1;

        foodX = rand () % BOARD_WIDTH;
        foodY = rand () % BOARD_HEIGHT;

        for ( i = 0; i < snakeLength; i ++)
        {
            if (snakeX[i] == foodX && snakeY[i] == foodY)
            {
                validPosition = 0;
                break;
            }
        }
    } while (!validPosition);
}

void drawFood (void)
{
    board[foodY][foodX] = '*';
}

void checkFoodCollision (void)
{
    if (snakeX[0] == foodX && snakeY[0] == foodY)
    {
        growSnake ();

        score ++;

        initializeFood();
    }
}