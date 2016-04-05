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
    void SquareAssign(vector<string> proc1);
    void SquareUnassign();
    void StructMaker(vector<string> proc1);
    string ActionReciever(string action, string details);
    void actionHandler(vector<string> action);
};



#endif // NETWORK_H
