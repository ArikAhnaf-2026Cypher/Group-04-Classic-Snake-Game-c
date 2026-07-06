#include "snake.h"
#include "board.h"

/* The Actual Snake Data (Snake position and size): */
int snakeX [MAX_SNAKE_LENGTH]; //x coordinate of the snake on the board
int snakeY [MAX_SNAKE_LENGTH]; //y coordinate of the snake on the board
int snakeLength = 3;

int direction = RIGHT; 

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

/*The movement of the Snake*/
void moveSnake (void)
{

    int i; 

    /*Move every body-segment forward*/

    for (i = (snakeLength - 1); i > 0; i --)
    {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    /*Move the head of the Snake*/

    switch (direction)
    {
        case RIGHT:
            snakeX[0]++;
            break;

        case LEFT:
            snakeX[0]--;
            break;

        case UP:
            snakeY[0]--;
            break;

        case DOWN:
            snakeY[0]++;
            break;
    }
}

/*Change the Snakes Direction: */
void changeDirection (int newDirection)
{
    /*Prevent the snake from illigaly reversing direction.*/

    if (direction == RIGHT && newDirection == LEFT)
    {
        return; //exits the function immediately when if is true
    }

    if (direction == LEFT && newDirection == RIGHT)
    {
        return; //exits the function immediately when if is true
    }

    if (direction == UP && newDirection == DOWN)
    {
        return; //exits the function immediately when if is true
    }

    if (direction == DOWN && newDirection == UP)
    {
        return; //exits the function immediately when if is true
    }

    direction = newDirection;

}