#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <QLabel>
#include <QGridLayout>
#include "player.h"
#include "roadrace.h"

using namespace std;

class Player;
class Structure{
    //resprsent type of pathway
    string type;
    string image;
    //set owner

    Player *owner;
    //set owning Sqaure e.g. Square 3X4 has a road on it
public:
    Structure(string ntype, string nimage, Player* nowner): type(ntype), image(nimage), owner(nowner){}
    //set a square's path
    virtual void build() = 0;
    //destory the path, but not the square
    virtual void destroy() = 0;
    //destructor
    virtual ~Structure(){}
    string getType() { return type; }
    string getImage() { return image; }
    Player *getOwner() { return owner; }
    void setType(string nt){type = nt;}
    void setImage(string ni){image = ni;}
    void setOwner(Player *no){owner = no;}

};
class Boat: public Structure{

};
class Tunnel: public Structure{

};
class Wall: public Structure{

};
class Bridge: public Structure{

};

class Square{
    string type;
    string image;
    Player *owner;
    string addition;
    Structure *path;
public:
    Square(string type_,string addition_,Player *owner_) : type(type_), image(type_), owner(owner_), addition(addition_){}
    Square(string type_,string addition_) : type(type_), image(type_), owner(NULL), addition(addition_){}
    Square(string type_) : type(type_), image(type_), owner(NULL), addition(""){}
    Square(string type_,Player *owner_) : type(type_), image(type_), owner(owner_), addition(""){}

    //TODO: make Square pure virtual with inherited types.
    //This will require updating in gamefile.cpp.
    //virtual bool mine()=0;
    //virtual bool destroy()=0;

    bool hasOwner () { return owner==NULL; }
    string getType() { return type; }
    string getImage() { return image; }
    Player *getOwner() { return owner; }
    string getAddition() { return addition; }

    void setType ( string t ) { type = t; }
    void setImage ( string i ) { image = i; }
    void setOwner ( Player *o ) { owner = o; }
    void setAddition ( string a ) { addition = a; }
};

class ForestSq: public Square{

};
class MountainSq: public Square{

};
class RiverSq: public Square{

};
class PlainSq: public Square{

};
class CanyonSq: public Square{

};

class SquareLabel : public QLabel{
    Q_OBJECT
    Square *square;
public:
    explicit SquareLabel (Square *square_, QWidget *parent): QLabel(parent), square(square_) {
    }

};




#endif // SQUARE_H
