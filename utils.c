// #include <windows.h>
// #include "utils.h"

// void moveCursorToTop(void)
// {
//     COORD position;

//     position.X = 0;
//     position.Y = 0;

//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
// }


// Version-02 (in hopes of better rendering)
#include <windows.h>
#include "utils.h"

void moveCursorToTop(void)
{
    HANDLE console;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD written;
    DWORD cells;
    COORD home = {0, 0};

    console = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(console, &csbi);

    cells = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(
        console,
        ' ',
        cells,
        home,
        &written
    );


    FillConsoleOutputAttribute(
        console,
        csbi.wAttributes,
        cells,
        home,
        &written
    );

    SetConsoleCursorPosition(console, home);
}
// #include <windows.h>
// #include "utils.h"

// void moveCursorToTop(void)
// {
//     HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

//     COORD position;
//     position.X = 0;
//     position.Y = 0;

//     SetConsoleCursorPosition(console, position);
// }


// void hideCursor(void)
// {
//     HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

//     CONSOLE_CURSOR_INFO cursorInfo;

//     cursorInfo.dwSize = 100;
//     cursorInfo.bVisible = FALSE;

//     SetConsoleCursorInfo(console, &cursorInfo);
// }
void hideCursor(void)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(console, &cursorInfo);

    cursorInfo.bVisible = FALSE;

    SetConsoleCursorInfo(console, &cursorInfo);
}