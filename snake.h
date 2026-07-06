//Include Guards as always

#ifndef SNAKE_H
#define SNAKE_H

#define MAX_SNAKE_LENGTH 100

extern int snakeX [MAX_SNAKE_LENGTH]; //global variable using extern
extern int snakeY [MAX_SNAKE_LENGTH]; //same as above
extern int snakeLength;

//Functions
void initializeSnake (void); //functions prototype
void drawSnake (void); //same as above

#endif 