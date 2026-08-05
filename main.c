/* 
The Conductor of
The Orchestra 
*/

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include "board.h"
#include "snake.h"
#include "food.h"
#include "input.h"
#include "utils.h"
//#include "game.h" (If we make this header file, we will use it hopefully XDDD)


int main (void)

{
    int gameRunning = 1;

    int gameSpeed = 250;

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
      if (score >= 25)
      {
        gameSpeed = 30;
      }
      else if (score >= 20)
      {
        gameSpeed = 50;
      }
      else if (score >= 15)
      {
        gameSpeed = 80;
      }
      else if (score >= 10)
      {
        gameSpeed = 110;
      }
      else if (score >= 5)
      {
        gameSpeed = 140;
      }
      else 
      {
        gameSpeed = 200;
      }


      // drawSnake ();

      // drawFood (); //Draws the food on the board

      // moveCursorToTop (); //moves the cursor every frame to the top

      // drawBoard (); //Display the whole complete board

      // if (!gameRunning)
      // {
      //     break;
      // }

      // Sleep (gameSpeed); //Pauses for 250 miliseconds

      if (!gameRunning)
      {
        /*
        Remove the snake and food, and place the 
        game - over inside the board.*/
        prepareGameOverBoard ();

        /*
        Clear the old frame and display the 
        "Game - Over" board as the final frame.
        */
       moveCursorToTop ();
       drawBoard ();

       break;
      }

      drawSnake ();

      drawFood ();

      moveCursorToTop ();

      drawBoard ();

      Sleep (gameSpeed);

    }

    _getch ();

    // printf ("\n");
    // printf ("==============================\n");
    // printf ("         GAME OVER!\n");
    // printf ("==============================\n");
    // printf ("Final Score : %d\n", score);
    // printf ("Snake Length: %d\n", snakeLength);
    // printf ("\n");
    // system ("Pause\n");

    return (0);

}