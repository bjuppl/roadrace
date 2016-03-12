#include "gamefile.h"
#include "gamemodel.h"

GameFileManager::GameFileManager (std::vector<std::string> contents ) {

    // /Users/jbrazeal/Desktop/School/2015-2016/Spring/CpS_209/TPfork/roadrace/road_race/gamefile.rr

    std::stringstream stream;

    for ( size_t i=0; i<contents.size();i++) {
        stream << contents[i] << std::endl;
    }

    const std::string fileIdentifier = "RoadRaceDoc",
            gameAlias = "alias",
            gamePassword = "password",
            roundNum = "round",
            playerList = "players",
            playerResourceList = "resources",
            playerStatus = "status",
            boardStart = "board",
            endFile = "EndRoadRaceDoc";

    while ( stream ) {
        std::string identifier;
        std::string command;
        stream >> identifier;

        if (identifier == fileIdentifier) {
            stream >> command;
            Game::instance().setId(command);
        } else if ( identifier)

    }
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
