//The fate for this file has not been destroyed yet!!!
#include <stdio.h>
#include <string.h>
#include "game.h"

struct GameData gameData = {0}; //so gameData.highscore will start from 0


void loadGameData (void)
{
    FILE *file; //creates a file pointer

    gameData.highscores [0] = 0;
    gameData.highscores [1] = 0;
    gameData.highscores [2] = 0;

    file = fopen ("data/highscores.txt", "r"); //open highscore.txt in read (r) mode

    if (file == '\0')
    {
        gameData.highscores [0];
        return;
    }
    //if the file has no values in it, then highscore will be 0

    fscanf (file, "%d", &gameData.highscores [0]); //reads the number from the file
    fscanf (file, "%d", &gameData.highscores [1]);
    fscanf (file, "%d", &gameData.highscores [2]);

    fclose (file); //closes the whole file
}


void saveGameData (void)
{
    FILE *file;

    file = fopen ("data/highscore.txt", "w"); //"w" = write mode

    if (file == '\0')
    {
        return;
    }

    fprintf (file, "%d\n", gameData.highscores [0]); //writes the highscore into the file
    fprintf (file, "%d\n", gameData.highscores [1]);
    fprintf (file, "%d\n", gameData.highscores [2]);

    fclose (file);
}


void updateHighScores (int currentScore) //this function does the comparison
{
    if (currentScore > gameData.highscores [0])
    {
        gameData.highscores [2] = gameData.highscores[1];
        gameData.highscores [1] = gameData.highscores[0];
        gameData.highscores [0] = currentScore;
    }
    else if (currentScore > gameData.highscores[1])
    {
        gameData.highscores [2] = gameData.highscores[1];
        gameData.highscores [1] = currentScore;
    }
    else if (currentScore > gameData.highscores[2])
    {
        gameData.highscores [2] = currentScore;
    }
    
    saveGameData ();
    
}

// void updateRank (void)
// {
//     if (gameData.highscore >= 10)
//     {
//         strcpy (gameData.rank, "GOLD");
//     }
//     else if
// }