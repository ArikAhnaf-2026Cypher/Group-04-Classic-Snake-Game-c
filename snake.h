#ifndef  SNAKE_H          // Start of include guard: only compile if SNAKE_H hasn't been defined yet
#define  SNAKE_H           // Define SNAKE_H so this file won't be included/processed again

#define MAX_SNAKE_LENGTH 100   // Constant: maximum number of segments the snake can have

#define UP 0                   // Constant representing the "up" direction (value 0)
#define DOWN 1                 // Constant representing the "down" direction (value 1)
#define LEFT 2                 // Constant representing the "left" direction (value 2)
#define RIGHT 3                // Constant representing the "right" direction (value 3)

extern int snakeX [MAX_SNAKE_LENGTH]; // Declares (doesn't define) array holding each snake segment's X coordinate; actual storage lives in a .c file
extern int snakeY [MAX_SNAKE_LENGTH]; // Same as above, but for Y coordinates of each segment

extern int snakeLength;   // Declares a global variable tracking the current length of the snake
extern int direction;     // Declares a global variable tracking the snake's current movement direction

//Functions
void initializeSnake (void);          // Prototype: sets up the snake's starting position/length before the game begins
void drawSnake (void);                // Prototype: renders the snake on screen
int moveSnake (void);                 // Prototype: moves the snake forward one step; returns a status (e.g., success/game-over)
void changeDirection (int newDirection); // Prototype: updates the snake's direction based on user input
int checkCollision (void);            // Prototype: checks if the snake has hit a wall or itself; returns true/false
void growSnake (void);                // Prototype: increases the snake's length (e.g., after eating food)

#endif   // End of include guard block
