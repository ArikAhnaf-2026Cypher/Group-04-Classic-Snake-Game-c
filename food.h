#ifndef FOOD_H
#define FOOD_H

extern int foodX; //global variable #1
extern int foodY; //global variable #2
/*These two global variables will tell us where the food is located.*/

void initializeFood (void);
void drawFood (void);
void checkFoodCollision (void);

#endif 