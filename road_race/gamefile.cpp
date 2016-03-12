#include "gamefile.h"
#include "gamemodel.h"
#include "player.h"
#include "square.h"
#include "utils.h"

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
            playerInfo = "info",
            playerResourceList = "resources",
            playerStatus = "status",
            boardStart = "board",
            endFile = "EndRoadRaceDoc";


    std::string identifier;
    std::string command;

    stream >> identifier;

    while ( stream ) {

        if (identifier == fileIdentifier) {
            stream >> command;
            Game::instance().setId(command);
        } else if ( identifier == gameAlias) {
            stream >> command;
            Game::instance().setAlias(command);
        } else if ( identifier == gamePassword ) {
            stream >> command;
            Game::instance().setPassword(command);
        } else if ( identifier == roundNum) {
            stream >> command;
            Game::instance().setRoundNum(stoi(command));
        } else if ( identifier == playerList ) {
            stream >> command;
            std::vector<std::string> names;
            std::vector<Player*> players;
            names = split(command,',');
            for (size_t i=0; i<names.size(); i++) {
                players.push_back(new Player(names[i]));
            }
            Game::instance().setPlayerList(players);
        } else if ( identifier == playerInfo) {
            stream >> command;
            Player * pl = Game::instance().getPlayer(command);
            if ( pl == NULL ) {
                std::cerr << "Player '" + command + "' not previously listed in game file." << std::endl;
                return;
            }
            stream >> identifier;
            if ( identifier == playerResourceList) {
                stream >> command;
                while ( command != playerStatus) {
                    std::vector<std::string> resource;
                    const std::string water = "Wa", gold = "Go", wood = "Wo", stone = "St";
                    resource = split(command, ',');

                    std::string type = resource[0];
                    int quantity = std::stoi(resource[1]);

                    if ( type == water ) {
                        pl->setWater(quantity);
                    } else  if ( type == gold ) {
                        pl->setGold(quantity);
                    } else  if ( type == wood ) {
                        pl->setWood(quantity);
                    } else  if ( type == stone ) {
                        pl->setStone(quantity);
                    }

                    stream >> command;
                }
                if ( command == playerStatus ) {
                    const int numStatusArgs = 2;
                    const std::string score = "score", startTime = "start_time";
                    for (int i=0; i<numStatusArgs; i++ ) {
                        stream >> command;
                        std::vector<std::string> statusItem;
                        statusItem = split(command,',');
                        std::string statusType = statusItem[0];
                        int statusQuantity = std::stoi(statusItem[1]);
                        if (statusType == score ) {
                            pl->setScore(statusQuantity);
                        } else if (statusType == startTime) {
                            pl->setStartTime(statusQuantity);
                        }
                    }
                }
            }
        } else if ( identifier == boardStart ) {
            stream >> command;
            std::vector<std::string> dim;
            dim = split(command,',');
            int x = stoi(dim[0]),
                    y = stoi(dim[1]);
            Game::instance().setHeight(x);
            Game::instance().setWidth(y);

            std::vector<std::vector<Square*>> squares;

            for ( int i=0; i<x; i++ ) {
                squares.push_back(vector<Square*>());
                for ( int j = 0; j<y; j++ ) {
                   stream >> command;
                   std::vector<std::string> square;
                   square = split(command,',');
                   std:string terrain = square[0],
                           addition = square[1],
                           ownerName = square[2];
                   Player *owner = Game::instance().getPlayer(ownerName);
                   squares[i].push_back( new Square(terrain,addition,owner));
                }

            }
            Game::instance().setSquares(squares);
        } else if ( identifier == endFile ) {
            break;
        }

       stream >> identifier;
    }
}

GameFileManager *GameFileManager::fromFile( std::string fileName ) {

    if ( fileName.size() == 0) {
        fileName = "gamefile.rr";
    }
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
        std::cerr << "Game file '" << fileName << " does not exist.";
    }

    return new GameFileManager(contents);
}
