#include <windows.h>
#include "utils.h"

void moveCursorToTop(void)
{
    COORD position;

    position.X = 0;
    position.Y = 0;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}