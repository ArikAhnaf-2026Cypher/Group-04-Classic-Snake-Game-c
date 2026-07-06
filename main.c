/* 
The Conductor of
The Orchestra 
*/

#include <stdio.h>
#include <windows.h>

#include "board.h"
#include "snake.h"
#include "food.h"
#include "input.h"
#include "utils.h"


int main (void)

{
    int frame;


    initializeBoard (); //Create an empty board
    initializeSnake (); //Set the Snake's starting position
    initializeFood ();//sets the food on the board

    system ("cls");

    for (frame = 0; frame < 30; frame ++) //Repeats everything 30 times
    {

      clearBoard (); //Clear the board in every frame

      drawSnake (); //Draws a new snake in every frame, right after clearing the board

      drawFood (); //Draws the food on the board

      moveCursorToTop (); //moves the cursor every frame to the top

      drawBoard (); //DIsplay the whole complete board

      processInput (); //Read keyboard
      
      moveSnake (); //Draw the Snake onto the board

      Sleep (250); //Pauses for 250 miliseconds

    }

    return (0);

}