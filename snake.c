#include "snake.h"
#include "board.h"

/* The Actual Snake Data (Snake position and size): */
int snakeX [MAX_SNAKE_LENGTH]; //x coordinate of the snake on the board
int snakeY [MAX_SNAKE_LENGTH]; //y coordinate of the snake on the board
int snakeLength = 3;

/*Initialize The Snake (Defining the initializeSnake functions): */
void initializeSnake (void)
{
    snakeX [0] = 32; //snake head
    snakeY [0] = 6; //snake head

    snakeX [1] = 31; //snake body
    snakeY [1] = 6; //snake body

    snakeX [2] = 30; //snake tail
    snakeY [2] = 6; //snake tail
}

/*Draw The Snake Onto The Board (Defining the snakeDraw function): */
void drawSnake (void)
{
    int i;

    for (i = 0; i < snakeLength; i++)
    {
        board[snakeY[i]][snakeX[i]] = 'O';
    }
}