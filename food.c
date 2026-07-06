#include "food.h"
#include "board.h"

int foodX;
int foodY;

void initializeFood (void)
{

    foodX = 20;
    foodY = 5;

}

void drawFood (void)
{
    board[foodY][foodX] = '*';
}