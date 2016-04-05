#ifndef NETWORK_H
#define NETWORK_H

#include <QTcpSocket>
#include <string>
using namespace std;
class Network {
    QTcpSocket *global_socket;
   static Network *instance_;
   Network (){}

public:
   void handleData ( vector<string> data );
    static Network& instance();
    void setSocket(QTcpSocket *s);
    QTcpSocket *getSocket() { return global_socket; }
    void SquareAssign(vector<string> proc1);
    void SquareUnassign();
    void StructMaker(vector<string> proc1);
    string ActionReciever(string action, string details);
    void actionHandler(vector<string> action);
};



#endif // NETWORK_H
