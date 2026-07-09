/* Now we will writing the actual code for the Board of the snake Game*/-

#include <stdio.h>
#include "board.h"
#include "snake.h"
#include "food.h"
#include "utils.h"



// The 2D grid representing the game board boundaries and contents
char board[BOARD_HEIGHT][BOARD_WIDTH];
/**
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

/**
* Renders the entire game screen to the console.
* This includes the game title header, the current score/length stats,
* and the top boundary of the gameplay area.
*/
void drawBoard (void)

{
    int i, j;
    // --- 1. RENDER GAME HEADER ---
    setColor (COLOR_GREEN);
    printf ("==================================================\n");
    printf ("              CLASSIC SNAKE GAME\n");
    printf ("                  Group - 04\n");
    printf ("==================================================\n\n");  
    resetColor ();
    
    // --- 2. RENDER SCOREBOARD ---
    setColor (COLOR_BLUE);
    printf ("Score : [%02d]\n", score);
    printf ("Length: [%02d]\n\n", snakeLength);
    resetColor ();
    
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
    for (i = 0; i < BOARD_HEIGHT; i++)
    {
        setColor (COLOR_CYAN);
        printf ("|"); // Draw left vertical boundary wall
        resetColor ();

        for (j = 0; j < BOARD_WIDTH; j++)
        {
            // printf ("%c", board[i][j]); //print whatever charecter is inside this board cell
            if (board[i][j] == '@')
            {
                // Render the snake's head
                setColor (COLOR_YELLOW);
                printf ("@");
                resetColor ();
            }

            else if (board[i][j] == 'O')
            {
                // Render the snake's body segments
                setColor (COLOR_YELLOW);
                printf ("O");
                resetColor ();
            }

            else if (board[i][j] == '*')
            {
                // Render food pieces
                setColor (COLOR_RED);
                printf ("*");
                resetColor ();
            }

            else 
            {
                // Render empty spaces or background titles
                printf ("%c", board[i][j]);
            }
        }

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

    // ---6. RENDER GAME CONTROLS ---
    printf ("Controls:\n");
    printf ("W  -  Move Up\n");
    printf ("A  -  Move Left\n");
    printf ("S  -  Move Down\n");
    printf ("D  -  Move Right\n");
}
