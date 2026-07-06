//Include Guards as always

#ifndef SNAKE_H
#define SNAKE_H

#define MAX_SNAKE_LENGTH 100

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

extern int snakeX [MAX_SNAKE_LENGTH]; //global variable using extern
extern int snakeY [MAX_SNAKE_LENGTH]; //same as above
extern int snakeLength;
extern int direction;

//Functions
void initializeSnake (void); //functions prototype
void drawSnake (void); //same as above
void moveSnake (void); //same as above
void changeDirection (int newDirection); //yet another function prototype

#endif 