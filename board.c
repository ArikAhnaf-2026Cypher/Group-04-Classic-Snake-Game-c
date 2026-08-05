/* Now we will writing the actual code for the Board of the snake Game*/

#include <stdio.h>
#include <string.h> //new
#include "board.h" 
#include "snake.h"
#include "food.h"
#include "utils.h"



// The 2D grid representing the game board boundaries and contents
char board[BOARD_HEIGHT][BOARD_WIDTH];

static int showingGameOver = 0;

/*
* Intializes the game board to empty state at program start.
* Fills every cell of the 2D board array with space characters
* to ensure no garbage values are displayed during first render 
*/ 
void initializeBoard (void) 
{

    int row, col;

    for (row = 0; row < BOARD_HEIGHT; row++)
    {
        for (col = 0; col < BOARD_WIDTH; col++)
        {
            board[row][col] = ' ';
        }
    }
    
}

/**
* Resets the entire game board grid.
* Iterates through every row and column to fill the board with empty spaces.
*/

void clearBoard (void) 
                       
                            
{
    int row, col;
    
    // Iterate through each row of the grid
    for (row = 0; row < BOARD_HEIGHT; row++)
    {
       // Iterate through each column within the current row 
        for (col = 0; col < BOARD_WIDTH; col++)
        {
            board [row][col] = ' ';
        }
    }
}

/*
Writes one line of text in the horizontal center of the board.
This function only changes the board array.
*/
static void writeCenteredText (int row, const char text [])
{
    int length, StartingColumn, i;

    length = (int) strlen (text);
    StartingColumn = (BOARD_WIDTH - length) / 2;

    for (i = 0; i < length; i++)
    {
        board [row] [StartingColumn + i] = text [i];
    }
}

/*
Prepares the contents that will be inside of the board when the game finishes.
*/
void prepareGameOverBoard (void)
{
    char scoreText [30];
    char lengthText [30];

    showingGameOver = 1;

    clearBoard ();

    sprintf (scoreText, "Final Score : %d", score);
    sprintf (lengthText, "Snake Length : %d", snakeLength);

    writeCenteredText (3, "==============================");
    writeCenteredText (4, "GAME OVER!");
    writeCenteredText (5, "==============================");

    writeCenteredText (7, scoreText);
    writeCenteredText (8, lengthText);

    writeCenteredText (10, "Press Any Key To Continue");
}

/*
* Renders the entire game screen to the console.
* This includes the game title header, the current score/length stats,
* and the top boundary of the gameplay area.
*/
void drawBoard (void)

{
    int i, j;
    // --- 1. RENDER GAME HEADER ---
    
    setColor (COLOR_GREEN);
    printf ("===================================================================\n");
    resetColor ();

    setColor (COLOR_CYAN);
    printf ("                         CLASSIC SNAKE GAME\n");
    resetColor ();

    setColor (COLOR_CYAN);
    printf ("                             Group - 04\n");
    resetColor ();

    setColor (COLOR_CYAN);
    printf ("                    Eat Hearts. Grow. Stay Alive.\n");
    resetColor ();

    setColor (COLOR_GREEN);
    printf ("===================================================================\n\n"); 
    resetColor ();

    /*----------------- Hud Headings ----------------*/

    setColor (COLOR_CYAN);

    printf ("% - 32s", "CONTROLS:");
    printf ("GAME INFO:\n");

    printf ("% - 32s", "---------");
    printf ("----------\n");

    resetColor ();

    /* ----------------CONTROLS AND GAME INFORMATION-----------------*/

    setColor (COLOR_WHITE);
    printf ("% - 32s", "W  -  Move Up");

    if (showingGameOver)
    {
        setColor (COLOR_RED);
        printf ("Status : [The Serpent Has Fallen]\n");
    }
    else
    {
        setColor(COLOR_BLUE);
        printf ("Status : [Slithering...]\n");
    }

    setColor (COLOR_WHITE);
    printf ("% - 32s", "A  -  Move Left");

    setColor (COLOR_BLUE);
    printf ("Score  : [%02d]\n", score);

    setColor (COLOR_WHITE);
    printf ("% - 32s", "S  -  Move Down");

    setColor (COLOR_BLUE);
    printf ("Length : [%02d]\n", snakeLength);

    setColor (COLOR_WHITE);
    printf ("% - 32s", "D  -  Move Right");

    printf ("\n\n");

    resetColor();
    
    // --- 2. RENDER SCOREBOARD ---
    // setColor (COLOR_BLUE);
    // printf ("Score : [%02d]\n", score);
    // printf ("Length: [%02d]\n\n", snakeLength);
    // resetColor ();
    
    // --- 3. RENDER TOP BORDER ---
    setColor (COLOR_CYAN);
    printf ("+"); // Top-left corner
    
    // Draw horizontal top wall
    for (i = 0; i < BOARD_WIDTH; i++)
    {

        printf ("-");
    }

    printf ("+\n"); // Top-right corner and newline
    resetColor ();
    
    // --- 4. RENDER PLAYFIELD SIDEWALLS AND CELLS ---
    // for (i = 0; i < BOARD_HEIGHT; i++)
    // {
    //     setColor (COLOR_CYAN);
    //     printf ("|"); // Draw left vertical boundary wall
    //     resetColor ();

    //     for (j = 0; j < BOARD_WIDTH; j++)
    //     {
    //         // printf ("%c", board[i][j]); //print whatever charecter is inside this board cell
    //         if (board[i][j] == '@')
    //         {
    //             // Render the snake's head
    //             setColor (COLOR_YELLOW);
    //             printf ("@");
    //             resetColor ();
    //         }

    //         else if (board[i][j] == 'O')
    //         {
    //             // Render the snake's body segments
    //             setColor (COLOR_YELLOW);
    //             printf ("O");
    //             resetColor ();
    //         }

    //         else if (board[i][j] == '*')
    //         {
    //             // Render food pieces
    //             setColor (COLOR_RED);
    //             printf ("*");
    //             resetColor ();
    //         }

    //         else 
    //         {
    //             // Render empty spaces or background titles
    //             printf ("%c", board[i][j]);
    //         }
    //     }

    //     setColor (COLOR_CYAN);
    //     printf ("|\n");
    //     resetColor ();
    // }

    for (i = 0; i < BOARD_HEIGHT; i++)
    {
        //Draw the left wall
        setColor (COLOR_CYAN);
        printf ("|");
        resetColor ();

        if (showingGameOver)
        {
            /*
            Select a color depending on which 
            game over message row is being printed.
            */

            if (i == 4)
            {
                //GAME OVER!
                setColor (COLOR_RED);
            }
            else if (i == 3 || i == 5)
            {
                //The lines above and bellow Game Over
                setColor (COLOR_GREEN);
            }
            else if (i ==7 || i == 8)
            {
                //Final score and snake length
                setColor (COLOR_MAGENTA);
            }
            else if (i == 10)
            {
                //Press any key message
                setColor (COLOR_CYAN);
            }

            /*
            Print the game over text normally.
            Don NOT treat O as a snake body in this part.
            */
           for (j = 0; j < BOARD_WIDTH; j++)
           {
            printf ("%c", board [i] [j]);
           }

           resetColor ();
        }
        else 
        {
            /*
            Normal Gmae Drawing.
            Here, @ means head, O means body, 
            and * means food.
            */

            for (j = 0; j < BOARD_WIDTH; j++)
            {
                if (board [i] [j] == '@')
                {
                    setColor (COLOR_YELLOW);
                    printf ("@");
                    resetColor ();
                }
                else if (board [i] [j] == 'O')
                {
                    setColor (COLOR_YELLOW);
                    printf ("O");
                    resetColor ();
                }
                else if (board [i] [j] == '*')
                {
                    setColor (COLOR_RED);
                    printf ("\xE2\x9D\xA4"); //BIG HEART XD
                    resetColor();
                }
                else 
                {
                    printf ("%c", board [i] [j]);
                }
            }
        }
        /*
        Draw the right wall*/
        setColor (COLOR_CYAN);
        printf ("|\n");
        resetColor ();
    }

    // --- 5. RENDER BOTTOM BORDER ---
    setColor (COLOR_CYAN);
    printf ("+"); // Bottom-left corner 
    
    // Draw horizontal bottom wall
    for (i = 0; i < BOARD_WIDTH; i++)
    {
        printf ("-");
    }

    printf ("+\n"); // Bottom-rigth corner and newline
    resetColor ();

    // // ---6. RENDER GAME CONTROLS ---
    // printf ("Controls:\n");
    // printf ("W  -  Move Up\n");
    // printf ("A  -  Move Left\n");
    // printf ("S  -  Move Down\n");
    // printf ("D  -  Move Right\n");
}
