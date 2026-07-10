#include "snake.h"//snake related declarations(struct/consts/prototypes)
#include "board.h"//Board dimensions and the board [][] array

/* snake state */
int snakeX [MAX_SNAKE_LENGTH]; //x-coordinates of every snake segment
int snakeY [MAX_SNAKE_LENGTH]; //y coordinates of every snake segment
int snakeLength = 3;  //current number of segments in the snake

int direction = RIGHT; //current movement direction

/* Sets up snake's starting position and length */
void initializeSnake (void)
{
    snakeX[0] = 32;   // Head x-position
    snakeY[0] = 6;    // Head y-position
    snakeX[1] = 31;   // First body segment x-position
    snakeY[1] = 6;    // First body segment y-position
    snakeX[2] = 30;   // Tail x-position
    snakeY[2] = 6;    // Tail y-positio
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

void drawSnake(void)
{
    int i;   // Loop counter for body segments
 
    /* Draw the head */
    if (snakeX[0] >= 0 && snakeX[0] < BOARD_WIDTH &&      // Head x is within bounds
        snakeY[0] >= 0 && snakeY[0] < BOARD_HEIGHT)        // Head y is within bounds
    {
        board[snakeY[0]][snakeX[0]] = '@';   // Mark head on the board
    }
 
    /* Draw the body (everything between head and tail) */
    for (i = 1; i < snakeLength - 1; i++)   // Skip index 0 (head) and last index (tail)
    {
        if (snakeX[i] >= 0 && snakeX[i] < BOARD_WIDTH &&   // Segment x is within bounds
            snakeY[i] >= 0 && snakeY[i] < BOARD_HEIGHT)     // Segment y is within bounds
        {
            board[snakeY[i]][snakeX[i]] = 'O';   // Mark body segment on the board
        }
    }
 
    /* Draw the tail */
    if (snakeLength > 1)   // Only draw a distinct tail if there's more than just a head
    {
        if (snakeX[snakeLength - 1] >= 0 &&                 // Tail x is within bounds
            snakeX[snakeLength - 1] < BOARD_WIDTH &&
            snakeY[snakeLength - 1] >= 0 &&                 // Tail y is within bounds
            snakeY[snakeLength - 1] < BOARD_HEIGHT)
        {
            board[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = 'o';   // Mark tail on the board
        }
    }
}
 
/* Advances the snake by one step; returns 0 if it hit a wall, 1 otherwise */
int moveSnake(void)
{
    int i;   // Loop counter for shifting segments
 
    /* Shift every segment forward into the position of the one ahead of it */
    for (i = (snakeLength - 1); i > 0; i--)   // Work backwards so we don't overwrite data we still need
    {
        snakeX[i] = snakeX[i - 1];   // Segment i takes the x of the segment in front of it
        snakeY[i] = snakeY[i - 1];   // Segment i takes the y of the segment in front of it
    }
 
    /* Move the head based on current direction */
    switch (direction)
    {
        case RIGHT:
            snakeX[0]++;   // Move head right
            break;
        case LEFT:
            snakeX[0]--;   // Move head left
            break;
        case UP:
            snakeY[0]--;   // Move head up
            break;
        case DOWN:
            snakeY[0]++;   // Move head down
            break;
    }
 
    /* Check if the snake hit a wall */
    if (snakeX[0] < 0 || snakeX[0] >= BOARD_WIDTH)   // Head is outside horizontal bounds
    {
        return 0;   // Signal a wall collision
    }
 
    if (snakeY[0] < 0 || snakeY[0] >= BOARD_HEIGHT)   // Head is outside vertical bounds
    {
        return 0;   // Signal a wall collision
    }
 
    return 1;   // Move was successful
}
 
/* Grows the snake by one segment, placed on top of the current tail */
void growSnake(void)
{
    if (snakeLength < MAX_SNAKE_LENGTH)   // Only grow if there's room left in the arrays
    {
        snakeX[snakeLength] = snakeX[snakeLength - 1];   // New segment starts at old tail's x
        snakeY[snakeLength] = snakeY[snakeLength - 1];   // New segment starts at old tail's y
        snakeLength++;                                    // Increase the snake's length
    }
}
 
/* Checks whether the snake's head has hit a wall or its own body */
int checkCollision(void)
{
    int i;   // Loop counter for body segments
 
    if (snakeX[0] < 0 || snakeX[0] >= BOARD_WIDTH ||   // Head is outside horizontal bounds
        snakeY[0] < 0 || snakeY[0] >= BOARD_HEIGHT)     // Head is outside vertical bounds
    {
        return 1;   // Wall collision
    }
 
    for (i = 1; i < snakeLength; i++)   // Check head against every body segment
    {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])   // Head overlaps a body segment
        {
            return 1;   // Self collision
        }
    }
 
    return 0;   // No collision
}
 
/* Updates the snake's direction, ignoring illegal 180-degree reversals */
void changeDirection(int newDirection)
{
    if (direction == RIGHT && newDirection == LEFT)   // Can't reverse from right to left
    {
        return;
    }
    if (direction == LEFT && newDirection == RIGHT)   // Can't reverse from left to right
    {
        return;
    }
    if (direction == UP && newDirection == DOWN)      // Can't reverse from up to down
    {
        return;
    }
    if (direction == DOWN && newDirection == UP)      // Can't reverse from down to up
    {
        return;
    }
 
    direction = newDirection;   // Direction change is legal, so apply it
}
//version-02, in hopes to make the final product more refined

