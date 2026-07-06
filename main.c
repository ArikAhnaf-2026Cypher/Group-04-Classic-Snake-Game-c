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
    int frame;

    srand (time (NULL) );


    initializeBoard (); //Create an empty board
    initializeSnake (); //Set the Snake's starting position
    initializeFood ();//sets the food on the board

    system ("cls");

    while (1) //Repeats everything 30 times
    {

      clearBoard (); //Clear the board in every frame

      processInput (); //Read keyboard
      
      moveSnake (); //Draw the Snake onto the board
      
      checkFoodCollision(); //checks if the snake collided with the food or not
      
      drawSnake (); //Draws a new snake in every frame, right after clearing the board

      drawFood (); //Draws the food on the board

      moveCursorToTop (); //moves the cursor every frame to the top

      drawBoard (); //DIsplay the whole complete board

      Sleep (250); //Pauses for 250 miliseconds

    }

    return (0);

}