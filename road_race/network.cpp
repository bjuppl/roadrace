#include "network.h"
#include "gamemodel.h"
#include "player.h"
#include "gui.h"
#include "squarelabel.h"
#include <memory>
#include <string>
#include <QDebug>
#include "utils.h"
#include "levelmanager.h"
#include <sstream>

#include <QMessageBox>

class LevelManager;
Network *Network::instance_ = NULL;
Network& Network::instance() {
    if ( instance_ == NULL ) {
        instance_ = new Network;
    }
    return *instance_;
}

void Network::handleData(vector<string> data){
    vector<QString> gamefile;
    bool firstLineGone = false,
            start_load = false,
            prep = false,
            owner = false;
    for ( size_t i=0; i<data.size(); i++ ) {
        if ( data[i].size() == 0 || data[i] == "\n" ) {
            continue;
        }
        vector<string> conts = split(data[i],' ');

        stringstream strm;
        strm.str(data[i]);

        string command = "";

        strm >> command;

        cout << "Command: " << command << endl;

        //Start a full game doc
        if (command == "RoadRaceDoc" || start_load ) {
            firstLineGone = true;
            start_load = true;
            prep = true;
            gamefile.push_back(QString::fromStdString(split(data[i],'\n')[0]));
        }

        if ( command == "EndRoadRaceDoc" && start_load ) {
            start_load = false;
            LevelManager::instance().prepSquares(gamefile);
            prep = false;
            continue;
        }

        if ( start_load) {
            continue;
        }



        //Other communications initiated by server

        const string OWN = "own",
                GET = "get",
                CHANGE = "change",
                KILL = "kill",
                GAME_JOINED = "game_joined",
                START_GAME = "start_game",
                GAME_INIT = "game_init",
                GAME_NO_INIT = "game_no_init",
                ALIAS_FAIL = "alias_fail",
                NAME_FAIL = "name_fail",
                PASSWORD_FAIL = "password_fail",
                PLAYER_LIST = "player_list",
                GAME_DATA = "game_data";


        QWidget *q = GuiManager::instance().getUi()->centralWidget;
        if ( command == GAME_JOINED ) {
            //QMessageBox::information(q, "Welcome","Thanks for joining the game! It will start shortly.");
            continue;
        }

        if ( command == GAME_DATA ) {
            continue;
        }

        else if ( command == START_GAME ) {
            QMessageBox::information(q, "Game starting!","Everyone joined!");
            continue;
        }

        else if ( command == GAME_INIT ) {
            return;
        }

        else if ( command == PLAYER_LIST ) {
            continue;
        }

        else if ( command == GAME_NO_INIT ) {
            QMessageBox::critical(q, "Hmm","Unable to start this game.");
            return;
        }

        else if ( command == ALIAS_FAIL ) {
            QMessageBox::critical(q, "Hmm","That game alias is already taken, sry.");

            return;
        }

        else if ( command == NAME_FAIL ) {
            QMessageBox::critical(q, "Hmm","A player in this game already HAS that name.");
            return;
        }

        else if ( command == PASSWORD_FAIL ) {
            QMessageBox::critical(q, "Hmm","That password is incorrect!");
            return;
        }


        //Otherwise
        string player_name = command;

        Player * p = Game::instance().getPlayer(player_name);

        if ( p == nullptr ) {
            cout << "The player " << player_name << " does not exist. " << endl;
            return;
        }

        strm >> command;

        while ( strm ) {
            if ( command == OWN ) {

                strm >> command;

                vector<string> coords;
                QString qs = QString::fromStdString(command);
                QStringList ql = qs.split(',');

                for ( size_t i=0; i<ql.size(); i++ ) {
                    cout << "Coordinate " << i << ": " << ql[i].toStdString() << endl;
                }

                if ( ql.size() < 2 ) {
                    cout << "Coordinates not specified: " << command << endl;
                    return;
                }

                int x, y;
                try {
                    x = ql.at(0).toInt();
                    y = ql.at(1).toInt();
                } catch (...) {
                    cout << "Coordinates invalid: " << ql.at(0).toStdString() << "," << ql.at(1).toStdString() << "." << endl;
                    return;
                }

                cout << "x: " << x << endl;
                cout << "y: " << y << endl;

                Square *s = Game::instance().getSquare(x,y);

                if ( s == nullptr  ) {
                    cout << "Coordinates out of bounds: " << ql[0].toStdString() << "," << ql[1].toStdString() << "." << endl;
                    return;
                }

                s->setOwner(p);

                Network::instance().SquareAssign( p, s );
                cout << "Square at " << ql[0].toStdString() << "," << ql[1].toStdString() << " changed owners to " << p->getName() << endl;

                return;


            } else if ( command == GET ) {

                strm >> command;

                const string GAMEFILE = "gamefile",
                        DRAGON = "dragon";

                if ( !strm ) {
                    cout << "Invalid GET command. What do you even want?" << endl;
                    return;
                }

                if (command == GAMEFILE) {
                    cout << "GET GAMEFILE -- This should hopefully have been handled by the server" << endl;
                } else if ( command  == DRAGON ) {
                    cout << "GET DRAGON -- command not currently supported. Too bad." << endl;
                } else {
                    // Building an addition
                    string type;
                    strm >> type;

                    if ( !strm ) {
                        cout << "What type of addition did you want to build? " << endl;
                        return;
                    }

                    vector<string> coords;
                    QString qs = QString::fromStdString(command);
                    QStringList ql = qs.split(',');

                    for ( size_t i=0; i<ql.size(); i++ ) {
                        cout << "Coordinate " << i << ": " << ql[i].toStdString() << endl;
                    }

                    if ( ql.size() < 2 ) {
                        cout << "Coordinates not specified: " << command << endl;
                        return;
                    }

                    int x, y;
                    try {
                        x = ql.at(0).toInt();
                        y = ql.at(1).toInt();
                    } catch (...) {
                        cout << "Coordinates invalid: " << ql.at(0).toStdString() << "," << ql.at(1).toStdString() << "." << endl;
                        return;
                    }

                    cout << "x: " << x << endl;
                    cout << "y: " << y << endl;

                    Square *s = Game::instance().getSquare(x,y);

                    if ( s == nullptr  ) {
                        cout << "Coordinates out of bounds: " << ql[0].toStdString() << "," << ql[1].toStdString() << "." << endl;
                        return;
                    }


                    Network::instance().StructMaker( p, s, type );
                    cout << "Structure " << type << " added at " << ql[0].toStdString() << "," << ql[1].toStdString() << "." << endl;

                    return;
                }

            } else if ( command == CHANGE ) {

            } else if ( command == KILL ) {

            } else if ( command == GAME_JOINED ) {

            } else {
                cout << "I didn't really know what to do with command: " << command << endl;
                return;
            }


            strm >> command;
        }

    }
}

//Fix:: potential for a memory leak here
void Network::setSocket(QTcpSocket *s){
    if (global_socket != nullptr) {
        //global_socket->disconnectFromHost();
        //global_socket->deleteLater();
    }

    global_socket = s;
}

void Network::SquareAssign(Player *player, Square *sq){
    sq->setOwner(player);
    int x = sq->getX();

    int y = sq->getY();

    int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/Game::instance().getSquares().size()/2;

    QSize size1(size,size);

    //SquareLabel *lbl = dynamic_cast<SquareLabel*>(GuiManager::instance().getUi()->gameLayout->itemAtPosition(x,y));

    sq->getLabel()->setStyleSheet("border:" + QString::fromStdString(to_string(sq->getBorder())) + "px solid " + QString::fromStdString(sq->getOwner()->getColor()));

}
void Network::StructMaker(Player *player,Square *sq1, string structname){
    if(sq1->getOwner() == player){
    Structure *struct1 = Game::instance().getStructure(structname);
    sq1->setStruct(struct1);
    sq1->setAddition(structname);
    int x = sq1->getX();
    int y = sq1->getY();
    int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/Game::instance().getSquares().size()/2;
     QSize size1(size,size);
    QPixmap thing = GuiManager::instance().setmap(sq1,size1);
    sq1->getLabel()->setPixmap(thing);
    }
}
void Network::changeType(Square *square, string type){
    square->setType(type);
    Structure *stru = Game::instance().getStructure("Ru");
    square->setStruct(stru);
    square->setAddition("No");
    int x = square->getX();
    int y = square->getY();
    int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/Game::instance().getSquares().size()/2;
    QSize size1(size,size);
    QPixmap thing = GuiManager::instance().setmap(square,size1);
    square->getLabel()->setPixmap(thing);
}

string Network::ActionReciever(string action, string details){
    string result = "game " + Game::instance().getId() + " player " + Game::instance().getCurPlayer()->getName() + "\n";
    if ( action == "Win") {
        result += Game::instance().getCurPlayer()->getName() + " win";
        Network::instance().say(result);
        return result;
    }
   if(action == "New Owner"){

       string str1;
       str1 += details.at(0);
       string str2;
       str2 += details.at(2);
       int x = stoi(str1);
       int y = stoi(str2);
       int index = 3;
       string playername;
       while(index < (details.size())){
           playername += details.at(index);
           index++;
       }

       result += " own " + to_string(x) + "," + to_string(y);
       if(Game::instance().getIsLocalGame() == true)
       {
      Network::instance().say(result);
   }
       return result;
   }
   if(action == "New Struct"){
       string str1;
       str1 += details.at(0);
       string str2;
       str2 += details.at(2);
       int x = stoi(str1);
       int y = stoi(str2);
       int index = 3;
       string structname;

           structname += details.at(3);
           index++;
           structname += details.at(4);
           structname += details.at(5);
       result +=" get " + to_string(x) + "," + to_string(y) + structname;
       //qDebug() << QString::fromStdString(result);
       if(Game::instance().getIsLocalGame() == true)
       {
      Network::instance().say(result);
   }
       return result;

   }
   if (action == "Change type"){
       //string result;
       string str1;
       str1 += details.at(0);
       string str2;
       str2 += details.at(2);
       int x = stoi(str1);
       int y = stoi(str2);
       int index = 3;
       string typename1;
       while(index < (details.size())){
           typename1 += details.at(index);
           index++;
       }
       result = " change " + to_string(x) + "," + to_string(y);
       //qDebug() << QString::fromStdString(result);
       if(Game::instance().getIsLocalGame() == true)
       {
      Network::instance().say(result);
   }
       return result;
   }
    if(Game::instance().getIsLocalGame() == true)
    {
   Network::instance().say(result);
}
   return result;
}

void Network::say(string out) {
    out += "\n";
    QString test = QString::fromStdString(out);
    qDebug() << test;
    if(Game::instance().getIsLocalGame() != false){
    this->global_socket->write(QString::fromStdString(out).toLocal8Bit());
    }
}

void Network::actionHandler(vector<string> action){

    if(action.at(1) == "assign"){
        if(Game::instance().getCurPlayer()->getName() != action.at(0)){
        //SquareAssign(action);
    }
    }
        if(action.at(0) == "build"){


            //StructMaker(action);

        }
}
    //update struct

    //update player

    //update misc.

