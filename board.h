/*Include Guards*/
#ifndef BOARD_H //If this file hasen't been included before...
#define BOARD_H //Mark this file as included

/*Board Dimensions*/
#define BOARD_WIDTH 65 //macro 01
#define BOARD_HEIGHT 12 //macro 02

/* The game board stored in memory*/
extern char board[BOARD_HEIGHT][BOARD_WIDTH];

/*Functions*/
void initializeBoard (void); //Function prototype
void drawBoard (void); //Function prototype

#endif //Finished!