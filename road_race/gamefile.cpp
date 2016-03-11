#include "gamefile.h"

GameFileManager::GameFileManager (std::vector<std::string> contents ) {


}

GameFileManager *GameFileManager::fromFile( std::string fileName ) {

    std::string line;

    std::vector<std::string> contents;
    std::ifstream gamefile (fileName);
    if (gamefile.is_open())
    {
      while ( std::getline (gamefile,line) )
      {
        contents.push_back(line);
      }
      gamefile.close();
    }

    else {
        std::cerr << "Game file " << fileName << " does not exist.";
    }

    return new GameFileManager(contents);
}
