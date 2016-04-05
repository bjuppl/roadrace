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
    bool start_load = false, prep = false;
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

void Network::SquareAssign(vector<string> proc1){
    int x;
    int y;
    string sizestr = proc1.at(2);
    string str1;
    string str2;
    qDebug() << QString::fromStdString(sizestr);
    str1 += sizestr.at(0);
    str2 += sizestr.at(2);
    x = stoi(str1);
    y = stoi(str2);
    Square *proc = Game::instance().getSquare(x,y);
    string name = proc1.at(0);
    int ss = Game::instance().getPlayerList().size();
    Player *reqPlayer = Game::instance().getPlayer(name);
    int index = 0;
   /* while(index < Game::instance().getPlayerList().size()){
        Player *test = Game::instance().getPlayerList().at(index);
        string x = test->getName();
        qDebug() << QString::fromStdString(x);
        index++;
   */
    qDebug() << QString::fromStdString(name);
    int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/Game::instance().getSquares().size()/2;
    proc->setOwner(reqPlayer);
    QSize size1(size,size);
    //SquareLabel *lbl = GuiManager::instance().getUi()->gridLayoutWidget->childAt(x,y);
    //lbl->setStyleSheet("border:" + QString::fromStdString(to_string(proc->getBorder())) + "px solid " + QString::fromStdString(proc->getOwner()->getColor()));
}
void Network::SquareUnassign(){
    int x;
    int y;

    Square *proc = Game::instance().getSquare(x,y);
    Player *none = nullptr;
    proc->setOwner(none);
    SquareLabel *lbl = proc->getLabel();
    lbl->setStyleSheet("border:" + QString::fromUtf8("black") + "px solid " + QString::fromUtf8("black"));


}
void Network::StructMaker(vector<string> proc1){
    int x;
    int y;
    string sizestr = proc1.at(2);
    string str1;
    string str2;
    qDebug() << QString::fromStdString(sizestr);
    str1 += sizestr.at(0);
    str2 += sizestr.at(2);
    x = stoi(str1);
    y = stoi(str2);
    Square *sqr = Game::instance().getSquare(x,y);
    SquareLabel *lbl = dynamic_cast<SquareLabel*>(GuiManager::instance().getUi()->gameLayout->itemAtPosition(x,y)->widget());
    Structure *addition;
    string name = proc1.at(3);
    addition = Game::instance().getStructure(name);
    sqr->setStruct(addition);
    sqr->setAddition(name);
     int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/Game::instance().getSquares().size()/2;
      QSize size1(size,size);
    QPixmap thing = GuiManager::instance().setmap(sqr,size1);
    lbl->setPixmap(thing);
}

string Network::ActionReciever(string action, string details){
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
       string result = "own " + to_string(x) + "," + to_string(y);
       qDebug() << QString::fromStdString(result);
       return result;
   }
   if(action == "New Struct"){
       string result;
       string str1;
       str1 += details.at(0);
       string str2;
       str2 += details.at(2);
       int x = stoi(str1);
       int y = stoi(str2);
       int index = 3;
       string structname;
       while(index < (details.size())){
           structname += details.at(index);
           index++;
       }
       result = "get " + to_string(x) + "," + to_string(y) + structname;
       qDebug() << QString::fromStdString(result);
       return result;

   }
   if(action == "Destroyed Struct"){
       string result;
       string str1;
       str1 += details.at(0);
       string str2;
       str2 += details.at(2);
       int x = stoi(str1);
       int y = stoi(str2);
       int index = 3;
       string structname;
       while(index < (details.size())){
           structname += details.at(index);
           index++;
       }
       result = "SB Square " + to_string(x) + "," + to_string(y) + " has removed " + structname;
       //qDebug() << QString::fromStdString(result);
       return result;

   }
   if (action == "Change type"){
       string result;
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
       result = "NT Square " + to_string(x) + "," + to_string(y) + " has changed to " + typename1;
       //qDebug() << QString::fromStdString(result);
       return result;
   }
   if (action == "New Sources"){
       string result = "NR ";
       string plname;
       vector<string> strs;
       char delim = ' ';
       strs = split(details,delim);
       plname = strs.at(0);
       int index = 1;
       result += plname + " ";
       while (index < strs.size()){

           if((strs.at(index) == "Wo") ||(strs.at(index) == "Wa") || (strs.at(index) == "Sto") || (strs.at(index) == "Go")){
               result+= strs.at(index) + ",";
           }
           else{
               result += strs.at(index) + " ";
           }
           index++;
       }
       return result;
   }
}
void Network::actionHandler(vector<string> action){

    if(action.at(1) == "assign"){
        if(Game::instance().getCurPlayer()->getName() != action.at(0)){
        SquareAssign(action);
    }
    }
        if(action.at(0) == "build"){


            StructMaker(action);

        }
}
    //update struct

    //update player

    //update misc.

