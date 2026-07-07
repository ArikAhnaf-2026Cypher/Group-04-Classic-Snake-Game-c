#ifndef UTILS_H
#define UTILS_H

#define COLOR_BLUE         9
#define COLOR_GREEN        10
#define COLOR_CYAN         11
#define COLOR_RED          12
#define COLOR_YELLOW       14
#define COLOR_WHITE        15

void moveCursorToTop (void);
void hideCursor (void);

/*Functions for coloring*/
void setColor (int color);
void resetColor (void);

#endif 