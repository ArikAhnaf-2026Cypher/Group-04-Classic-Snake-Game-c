/* Now we will be writing the actual code for the Board of the snake Game.*/

#include <stdio.h>
#include "board.h"

char board [BOARD_HEIGHT][BOARD_WIDTH];

void initializeBoard (void)
{

    int row, col;

    for (row = 0; row < BOARD_HEIGHT; row ++)
    {
        for (col = 0; col < BOARD_WIDTH; col ++)
        {
            board[row][col] = ' ';
        }
    }
    
}

void clearBoard (void)
{
    int row, col;

    for (row = 0; row < BOARD_HEIGHT; row ++)
    {
        for (col = 0; col < BOARD_WIDTH; col ++)
        {
            board [row][col] = ' ';
        }
    }
}
void drawBoard (void) //Defining the drawBoard function

{
    int i, j;


    printf ("==================================================\n");
    printf ("            CLASSIC SNAKE GAME\n");
    printf ("                Group - 04\n");
    printf ("==================================================\n\n");  
    
    printf ("Score : 0\n");
    printf ("Length: 3\n\n");

    printf ("+");

    for (i = 0; i < BOARD_WIDTH; i ++)
    {
        printf ("-");
    }

    printf ("+\n");

    for (i = 0; i < BOARD_HEIGHT; i++)
    {
        printf ("|");

        for (j = 0; j < BOARD_WIDTH; j++)
        {
            printf ("%c", board[i][j]); //print whatever charecter is inside this board cell
        }

        printf ("|\n");
    }


    printf ("+");

    for (i = 0; i < BOARD_WIDTH; i++)
    {
        printf ("-");
    }

    printf ("+\n");


    printf ("Controls:\n");
    printf ("W  -  Move Up\n");
    printf ("A  -  Move Left\n");
    printf ("S  -  Move Down\n");
    printf ("D  -  Move Right\n");
}