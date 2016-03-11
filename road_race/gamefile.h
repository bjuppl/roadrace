#ifndef GAMEFILE_H
#define GAMEFILE_H


#include <string>

class GameFileManager {

public:
    GameFileManager(std::string contents );
    static GameFileManager fromFile( std::string fileName );

};


#endif // GAMEFILE_H
