#include "network.h"
#include "gamemodel.h"
#include "player.h"
#include "gui.h"
#include "squarelabel.h"
#include <memory>
#include <string>
#include <QDebug>
#include "utils.h"
Network *Network::instance_ = NULL;
Network& Network::instance() {
    if ( instance_ == NULL ) {
        instance_ = new Network;
    }
    return *instance_;
}

void Network::SquareAssign(){
    int x;
    int y;

    Square *proc = Game::instance().getSquare(x,y);

    Player *reqPlayer;
    int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/Game::instance().getSquares().size()/2;
    proc->setOwner(reqPlayer);
    QSize size1(size,size);
    SquareLabel *lbl = proc->getLabel();
    lbl->setStyleSheet("border:" + QString::fromStdString(to_string(proc->getBorder())) + "px solid " + QString::fromStdString(proc->getOwner()->getColor()));
    GuiManager::instance().setmap(proc,size1);
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
       string result = "NO Square " + to_string(x) + "," + to_string(y) + " has changed hands to " +playername + ".";
       //qDebug() << QString::fromStdString(result);
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
       result = "NS Square " + to_string(x) + "," + to_string(y) + " has added " + structname;
       //qDebug() << QString::fromStdString(result);
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
void Network::actionHandler(QString actStr){

    //update square

    //update struct

    //update player

    //update misc.
}
