#include <conio.h>
#include "input.h"
#include "snake.h"

void processInput (void) //Defining processInput ()

{

    if (_kbhit()) //_kbhit checks if any key has been pressed
    {
        char key;

        key = _getch(); //_getch reads the key immediately (No enter key needed)

        if (key == 'w' || key == 'W')
        {
            changeDirection (UP);
        }

        else if (key == 's' || key == 'S')
        {
            changeDirection (DOWN);
        }

        else if (key == 'a' || key == 'A')
        {
            changeDirection (LEFT);
        }

        else if (key == 'd' || key == 'D')
        {
            changeDirection (RIGHT);
        }
    }
}