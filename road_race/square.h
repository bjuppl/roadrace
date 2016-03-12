#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include "player.h"

using namespace std;

class Player;

class Square{
    string type;
    string image;
    Player *owner;
    string addition;

public:
    Square(string type_,string addition_,Player *owner_) : type(type_), image(type_), addition(addition_), owner(owner_){}
    Square(string type_,string addition_) : type(type_), image(type_), addition(addition_), owner(NULL){}
    Square(string type_) : type(type_), image(type_), addition(""), owner(NULL){}
    Square(string type_,Player *owner_) : type(type_), image(type_), addition(""), owner(owner_){}

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



#endif // SQUARE_H
