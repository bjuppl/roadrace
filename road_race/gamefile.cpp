#include "gamefile.h"
#include "gamemodel.h"
#include "player.h"
#include "square.h"
#include "utils.h"

std::string GameFileManager::toGameFile() {

    std::string output = "";

    //Add header file
    output += "RoadRaceDoc " + Game::instance().getId() + "\n";

    //Add alias/password line
    output += "alias " + Game::instance().getAlias() + " password " + Game::instance().getPassword() + "\n";

    //Add round number
     output += "round " + std::to_string(Game::instance().getRoundNum()) + "\n";

    //Add player list
    output += "players ";

    for ( size_t i = 0; i<Game::instance().getPlayerList().size(); i++ ) {
        output += Game::instance().getPlayerList().at(i)->getName() + " ";
    }

    output += "\n";

    //Add player info
    for ( size_t i = 0; i<Game::instance().getPlayerList().size(); i++ ) {
        Player *p = Game::instance().getPlayerList().at(i);
        output += "info " + p->getName() + " resources ";
        output += "Go," + std::to_string(p->getGold()) + " ";
        output += "Wo," + std::to_string(p->getWood()) + " ";
        output += "St," + std::to_string(p->getStone()) + " ";
        output += "Wa," +std::to_string(p->getWater()) + " ";
        output += "status ";
        output += "score," + std::to_string(p->getScore()) + " ";
        output += "startTime," + std::to_string(p->getStartTime());
        output += "\n";
    }

    //Add board head
    output += "board " + std::to_string(Game::instance().getWidth()) + "," + std::to_string(Game::instance().getHeight()) + "\n";

    //Add board contents
    for ( size_t i=0; i<Game::instance().getSquares().size(); i++ ) {
        for ( size_t j=0; j<Game::instance().getSquares().at(i).size(); j++ ) {
            Square *s = Game::instance().getSquare(i,j);
               std::string type = s->getType(),
                       addition = s->getAddition(),
                       owner = s->getOwner() == NULL ? "" : s->getOwner()->getName();
              output += type + "," + addition + "," + owner + " ";
        }
        output += "\n";
    }

    //Add endfile
    output += "EndRoadRaceDoc";

    return output;

}

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
