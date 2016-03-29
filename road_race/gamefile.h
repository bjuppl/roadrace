#ifndef GAMEFILE_H
#define GAMEFILE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

class GameFileManager {

public:
    GameFileManager( std::vector<std::string> contents );
    static GameFileManager *fromFile( std::string fileName );
    GameFileManager(){}
    std::string toGameFile();

};


#endif // GAMEFILE_H
