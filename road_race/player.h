#ifndef PLAYER_H
#define PLAYER_H
#include "square.h"
#include <string>
#include <vector>

class Player
{
private:
    int goldCount;
    int woodCount;
    int stoneCount;
    int waterCount;
    string name;
    vector<Square*> squareList;
public:
    Player(string newName){
        name = newName;
    }
       void SetName(string name2){
           name = name2;
       }
       string getName(){
           return name;
       }
       int getWood(){
           return woodCount;
       }
       int getStone(){
           return stoneCount;
       }
       int getWater(){
           return waterCount;
       }
       int goldCount(){
           return goldCount;
       }
       vector<Square*> getSquares(){
           return squareList;
       }
};

#endif // PLAYER_H
