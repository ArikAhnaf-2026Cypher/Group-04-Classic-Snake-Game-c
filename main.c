/* 
The Conductor of
The Orchestra 
*/

#include <stdio.h>
#include "board.h"
#include "snake.h"

int main (void)

{

    initializeBoard (); //Create an empty board

    initializeSnake (); //Set the Snake's starting position

    drawSnake (); //Draw the Snake onto the board

    drawBoard (); //DIsplay the whole complete board


     return (0);
     
}