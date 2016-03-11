#ifndef SQUARE_H
#define SQUARE_H

#include <string>

using namespace std;

class Square{
    string type;
    string image;
    int id;
    int resources;

public:
    Square(string newtype,string newImage,int newResources){
        type = newtype;
        image = newtype;
        image = newImage;
    }
    virtual bool mine()=0;
    virtual bool destroy()=0;

};



#endif // SQUARE_H
