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
    bool start_load = false, prep = false,owner = false;
    for ( size_t i=0; i<data.size(); i++ ) {
        vector<string> conts = split(data[i],' ');
        //cout << conts[0] << endl;
        if (conts[0] == "RoadRaceDoc" || start_load ) {
            start_load = true;
            prep = true;
            gamefile.push_back(QString::fromStdString(split(data[i],'\n')[0]));
        } if ( start_load && conts[0] == "EndRoadRaceDoc") {
            start_load = false;
        }
        string proc = data.at(0);
        qDebug() << "proc is " + QString::fromStdString(proc);
        vector<string> proc2 = split(proc,' ');
        if(proc2.at(0) == "Ct"){
           // Network::instance().SquareAssign(proc2);
        }
    }
    if (prep) {
        LevelManager::instance().prepSquares(gamefile);
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
    SquareLabel *lbl = dynamic_cast<SquareLabel*>(GuiManager::instance().getUi()->gridLayoutWidget->childAt(x,y));
    lbl->setStyleSheet("border:" + QString::fromStdString(to_string(sq->getBorder())) + "px solid " + QString::fromStdString(sq->getOwner()->getColor()));
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
    SquareLabel *lbl = dynamic_cast<SquareLabel*>(GuiManager::instance().getUi()->gridLayoutWidget->childAt(x,y));
    QPixmap thing = GuiManager::instance().setmap(sq1,size1);
    lbl->setPixmap(thing);
    }
}

string Network::ActionReciever(string action, string details){
    string result = "game " + Game::instance().getId() + " player " + Game::instance().getCurPlayer()->getName() + "\n";
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

