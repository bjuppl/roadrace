#ifndef PLAYER_H
#define PLAYER_H
#include "square.h"
#include <string>
#include <vector>

class Player
{
private:
    int goldCount, woodCount, stoneCount, waterCount;
    int score;
    int startTime;
    string name;
    vector<Square*> squareList;
public:
    Player(string newName){
        name = newName;
    }
       void setName(string name2){ name = name2;}
       string getName(){ return name; }
       int getWood(){ return woodCount;}
       int getStone(){ return stoneCount; }
       int getWater(){ return waterCount; }
       int getGold(){  return goldCount;}
       int getScore(){  return score;}
       int getStartTime(){  return startTime;}

       vector<Square*> getSquares(){ return squareList; }
       void setWood(int newWood){ woodCount = newWood;}
       void setGold(int gold){ goldCount = gold;}
       void setStone(int stone){ stoneCount = stone; }
       void setWater(int water){ waterCount = water;}
       void setScore(int sc){ score = sc;}
       void setStartTime(int st){ startTime = st;}
};


#endif // PLAYER_H
