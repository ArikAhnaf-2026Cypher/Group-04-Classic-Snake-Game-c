/* 
The Conductor of
The Orchestra 
*/

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"
#include "snake.h"
#include "food.h"
#include "input.h"
#include "utils.h"


int main (void)

{
    int gameRunning = 1;

    srand (time (NULL) );


    initializeBoard (); //Create an empty board
    initializeSnake (); //Set the Snake's starting position
    initializeFood (); //sets the food on the board

    system ("cls");

    hideCursor ();

    while (gameRunning) //Repeats everything 30 times
    {

      clearBoard (); //Clear the board in every frame

      processInput (); //Read keyboard
      
      gameRunning = moveSnake ();

      if (gameRunning)
      {

        if (checkCollision())
        {
          gameRunning = 0;
        }

      }
      if (gameRunning)
      {
        checkFoodCollision ();
      }


      drawSnake ();

      drawFood (); //Draws the food on the board

      moveCursorToTop (); //moves the cursor every frame to the top

      drawBoard (); //Display the whole complete board

      if (!gameRunning)
      {
        break;
      }

      Sleep (250); //Pauses for 250 miliseconds

    }

    printf ("\n");
    printf ("==============================\n");
    printf ("         GAME OVER!\n");
    printf ("==============================\n");
    printf ("Final Score : %d\n", score);
    printf ("Snake Length: %d\n", snakeLength);
    printf ("\n");
    system ("Pause\n");

    return (0);

}