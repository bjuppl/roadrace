#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <QFile>
#include <QResource>
#include <QTextStream>
#include <QIODevice>

#include <iostream>
#include <string>
#include <vector>

#include "gui.h"
#include "utils.h"
struct difficultyStruct{
//mods change based on various difficulties
    int woodMod;
    int goldMod;
    int waterMod;
    int stoneMod;
    difficultyStruct(int wm, int gm, int wam, int stm){

        woodMod = wm;
        goldMod = gm;
        waterMod = wam;
        stoneMod = stm;

      }
    difficultyStruct(){}
};
class LevelManager {

private:
    int curLevel{0};
    static LevelManager *instance_;
    difficultyStruct *duff{new difficultyStruct()};
    LevelManager(){}
    //enable random events
    bool randEn = true;
    string burn;
 public:
    static LevelManager& instance();

    ~LevelManager() { delete instance_;
                      delete duff;
                    }
    void increaseLevel();
    std::vector<std::string> getLevel( std::string name );
    std::vector<std::string> getLevel( int num );

    std::vector<std::string> resourceFileContents( std::string alias );
    difficultyStruct *getDuff(){return duff;}
    bool getRand(){return randEn;}
    void setRand(bool rand){randEn = rand;}
    string upRec(int goodRes);
    string downRec(int badRes);
    bool killStruct(int hit,int wid);
    bool riverSquare(int hit,int wid);
    bool burnSquare(int hit, int wid);
    bool quakeSquare(int hit, int wid);
    bool eruption(int hit, int wid);
    void trader();
    string getBurn(){return burn;}
    vector<string> randWorld();
    void prepSquares(vector<QString> proc);
};



#endif // LEVELMANAGER_H
