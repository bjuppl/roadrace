#ifndef GAMEFILE_H
#define GAMEFILE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class GameFileManager {

public:
    GameFileManager( std::vector<std::string> contents );
    static GameFileManager *fromFile( std::string fileName );

};


#endif // GAMEFILE_H
