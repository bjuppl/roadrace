#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <vector>
#include <string>

using namespace std;


class HighScore
{
private:

    //vector to store the high score list during each run of the game
    vector<string> highScoreList;

public:

    //Checks to see if a high score file exists and creates it if it does not already exist
    //returns true if a file was already found and false if it had to create one.`
    bool load();

    //Adds a score to the loaded vector using a name, score and some info
    void addScore(string name, int score, string info);

    //Clears the current high score list
    void clearScore();

    //Prints out the high score list in a nicely formatted manner
    void print();

    //Update the highscore file with the updated information from the last game run
    void update();

};


#endif // HIGHSCORE_H

