#ifndef NETWORK_H
#define NETWORK_H

#include <QTcpSocket>
#include <string>
#include "gamemodel.h"
using namespace std;
//#include "player.h"
#include "square.h"

class Player;
class Square;
class RoadRace;


class Network {
    QTcpSocket *global_socket;
   static Network *instance_;
   Network (){}

public:
   void handleData ( vector<string> data );
    static Network& instance();
    void setSocket(QTcpSocket *s);
    QTcpSocket *getSocket() { return global_socket; }
void SquareAssign(Player *player, Square *sq);
    //void SquareUnassign();
    void StructMaker(Player *player,Square *sq, string structname);
    string ActionReciever(string action, string details);
    void actionHandler(vector<string> action);

    void say( string out );
};



#endif // NETWORK_H
