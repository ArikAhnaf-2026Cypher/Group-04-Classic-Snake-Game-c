/* Now we will be writing the actual code for the Board of the snake Game.*/

#include <stdio.h>
#include "board.h" //ARIK
#include "snake.h"
#include "food.h"
#include "utils.h"

char board [BOARD_HEIGHT][BOARD_WIDTH];



void initializeBoard (void) // the function for initializeBoard
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


    setColor (COLOR_GREEN);
    printf ("==================================================\n");
    printf ("              CLASSIC SNAKE GAME\n");
    printf ("                  Group - 04\n");
    printf ("==================================================\n\n");  
    resetColor ();
    
    setColor (COLOR_BLUE);
    printf ("Score : [%02d]\n", score);
    printf ("Length: [%02d]\n\n", snakeLength);
    resetColor ();

    setColor (COLOR_CYAN);
    printf ("+");

    for (i = 0; i < BOARD_WIDTH; i ++)
    {

        printf ("-");
    }

    printf ("+\n");
    resetColor ();

    for (i = 0; i < BOARD_HEIGHT; i++)
    {
        setColor (COLOR_CYAN);
        printf ("|");
        resetColor ();

        for (j = 0; j < BOARD_WIDTH; j++)
        {
            // printf ("%c", board[i][j]); //print whatever charecter is inside this board cell
            if (board[i][j] == '@')
            {
                setColor (COLOR_YELLOW);
                printf ("@");
                resetColor ();
            }

            else if (board[i][j] == 'O')
            {
                setColor (COLOR_YELLOW);
                printf ("O");
                resetColor ();
            }

            else if (board[i][j] == '*')
            {
                setColor (COLOR_RED);
                printf ("*");
                resetColor ();
            }

            else 
            {
                printf ("%c", board[i][j]);
            }
        }

        setColor (COLOR_CYAN);
        printf ("|\n");
        resetColor ();
    }


    setColor (COLOR_CYAN);
    printf ("+");

    for (i = 0; i < BOARD_WIDTH; i++)
    {
        printf ("-");
    }

    printf ("+\n");
    resetColor ();


    printf ("Controls:\n");
    printf ("W  -  Move Up\n");
    printf ("A  -  Move Left\n");
    printf ("S  -  Move Down\n");
    printf ("D  -  Move Right\n");
}
