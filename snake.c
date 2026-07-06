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
// void drawSnake(void)
// {
//     int i;

//     for (i = 0; i < snakeLength; i++)
//     {
//         if (snakeX[i] >= 0 &&
//             snakeX[i] < BOARD_WIDTH &&
//             snakeY[i] >= 0 &&
//             snakeY[i] < BOARD_HEIGHT)
//         {
//             board[snakeY[i]][snakeX[i]] = 'O';
//         }
//     }
// }

//version-02, in hopes to make the final product more refined
void drawSnake(void)
{
    int i;

    /* Draw the head */
    if (snakeX[0] >= 0 && snakeX[0] < BOARD_WIDTH &&
        snakeY[0] >= 0 && snakeY[0] < BOARD_HEIGHT)
    {
        board[snakeY[0]][snakeX[0]] = '@';
    }

    /* Draw the body */
    for (i = 1; i < snakeLength - 1; i++)
    {
        if (snakeX[i] >= 0 && snakeX[i] < BOARD_WIDTH &&
            snakeY[i] >= 0 && snakeY[i] < BOARD_HEIGHT)
        {
            board[snakeY[i]][snakeX[i]] = 'O';
        }
    }

    /* Draw the tail */
    if (snakeLength > 1)
    {
        if (snakeX[snakeLength - 1] >= 0 &&
            snakeX[snakeLength - 1] < BOARD_WIDTH &&
            snakeY[snakeLength - 1] >= 0 &&
            snakeY[snakeLength - 1] < BOARD_HEIGHT)
        {
            board[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = 'o';
        }
    }
}

/*The movement of the Snake*/
int moveSnake (void)
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
        
        /* Check if the snake hit a wall */
    
    if (snakeX[0] < 0 || snakeX[0] >= BOARD_WIDTH)
    {
        return 0;
    }
    
    if (snakeY[0] < 0 || snakeY[0] >= BOARD_HEIGHT)
    {
        return 0;
    }

    return 1;
} 

void growSnake (void)
{
    if (snakeLength < MAX_SNAKE_LENGTH)
    {
        snakeX[snakeLength] = snakeX[snakeLength - 1];
        snakeY[snakeLength] = snakeY[snakeLength - 1];

        snakeLength++;
    }
}

int checkCollision (void)
{
    int i;

    if (snakeX[0] < 0 || snakeX[0] >= BOARD_WIDTH ||
        snakeY[0] < 0 || snakeY[0] >= BOARD_HEIGHT)
    {
        return 1;
    }

    for (i = 1; i < snakeLength; i++)
    {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
        {
            return 1;
        }
    }

    return 0;
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