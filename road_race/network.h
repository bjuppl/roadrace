#ifndef NETWORK_H
#define NETWORK_H

#include <QTcpSocket>
#include <string>
using namespace std;
class Network {
   static Network *instance_;
   Network (){}

public:
    static Network& instance();
    void SquareAssign();
    void SquareUnassign();
    string ActionReciever(string action, string details);
    void actionHandler(QString actStr);
};



#endif // NETWORK_H
