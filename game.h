//Finally, this file will be used T-T
#ifndef GAME_H
#define GAME_H

/*Stores the information that should be remembered by the game, for examole "The Highscore"*/
//below is a user defined structure
struct GameData
{
    int highscores [3]; //user defined structure, highscore is one component of the struct data type "GameData"
    // char rank [20]; 
};

/*The first 'Global' GameData variable*/
extern struct GameData gameData;

/*High Score / File Functions (file processing part): */
void loadGameData (void);
void saveGameData (void);
void updateHighScores (int currentScore);
void updateRank (void);


#endif 