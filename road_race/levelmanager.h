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

    void increaseLevel();
    std::vector<std::string> getLevel( std::string name );
    std::vector<std::string> getLevel( int num );

    std::vector<std::string> resourceFileContents( std::string alias );

};


#endif // LEVELMANAGER_H
