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

class LevelManager {

private:
    int curLevel{0};
    static LevelManager *instance_;

    LevelManager(){}
 public:
    static LevelManager& instance();

    ~LevelManager() { delete instance_; }
    void increaseLevel();
    std::vector<std::string> getLevel( std::string name );
    std::vector<std::string> getLevel( int num );

    std::vector<std::string> resourceFileContents( std::string alias );

};

struct difficultyStruct{
    int woodMod;
    int goldMod;
    int waterMod;
    int stoneMod;
    difficultyStruct(int wm,int gm, int wam, int stm,){
          woodMod = wm;
          goldMod = gm;
          waterMod = wam;
          stoneMod = stm;
         }

};
struct easyStruct: public difficultyStruct{

};
struct medStruct: public difficultyStruct{

};
struct HardStruct: public difficultyStruct{

};

#endif // LEVELMANAGER_H
